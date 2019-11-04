#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include "../include/graph.h"

void Graph::DFS(Node &v)
{   
    for(int i = 0; i < v.adj.size(); i++){
        if (v.adj[i]->visited == false){
            DFS(*v.adj[i]);
        }            
    }

    v.visited = true;   
}


void Graph::topologicalSort_DFS(Node &v , stack<struct Node> &pilha) { 

    for(int i = 0; i < v.adj.size(); i++){
        if (v.adj[i]->visited == false){
            topologicalSort_DFS(*v.adj[i], pilha);
        }            
    } 
    pilha.push(v); 
    v.visited = true;
}

void Graph::topologicalSort(){
    stack<struct Node> pilha; 

    int peso;

    ofstream arquivo;
  
    for(int i =0; i < nodes.size(); i++) {
        nodes[i].visited = false;
    }
  
    for(int i =0; i < nodes.size(); i++){
        if (nodes[i].visited == false) {
            topologicalSort_DFS(nodes[i], pilha); 
        }
    } 

    cout << "Possivel ordenacao topologica: \n\n";

    while (!pilha.empty()) { 
        cout << pilha.top().id << " => " << pilha.top().nome << endl; 
        pilha.pop(); 
    }   

}


void Graph::insertNode(Node v) 
{
    nodes.push_back(v);
}

void Graph::insertEdge(int v, int w)
{
    nodes[v-1].adj.push_back(&nodes[w-1]);
    nodes[w-1].grau++;
}
