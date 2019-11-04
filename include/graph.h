#include <string>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <vector>

#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

struct Professor {
	int id;
	int habilidades;
	vector<struct Escola*> preferencias;
};

struct Escola {
	int id;
	int ocupadas;
	vector<int> habilidades;
	vector<struct Professor*> professores;
};

class Graph
{
    
	vector<struct Professor> professores;
  vector<struct Escola> escolas;

public:
    // void DFS(Node &v);

    // void topologicalSort_DFS(Node &v, stack<struct Node> &pilha);

    // void topologicalSort();

    // void insertNode(Node v);

    // void insertEdge(int v, int w);

};

#endif