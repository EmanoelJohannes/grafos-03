#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include "../include/graph.h"

//Aresta Edge
//No Node

using namespace std;

Graph::Graph() {}

Node::Node() {}

void Graph::addNode(School s)
{
    if (!checkSchool(s.id))
        schools.push_back(s);
    else
        cout << "Escola [E" << e.id << "] já existe no grafo.";
}

void Graph::addNode(Teacher t)
{
    if (!checkTeacher(t.id))
        teachers.push_back(t);
    else
        cout << "Professor [P" << p.id << "] já existe no grafo.";
}

bool Graph::checkSchool(int id)
{
    vector<Schools>::iterator it;
    for (it = schools.begin(); it != schools.end(); it++)
        if ((*it).id == id)
            return true;

    return false;
}

bool Graph::checkTeacher(int id)
{
    vector<Teacher>::iterator it;
    for (it = teachers.begin(); it != teachers.end(); it++)
        if ((*it).id == id)
            return true;

    return false;
}

Node &Graph::findSchool(int id)
{
    vector<School>::iterator i;
    for (i = schools.begin(); i != schools.end(); i++)
        if ((*i).id == id)
            return *i;

    throw "Argumento invalido.";
}

Node &Graph::findTeacher(int id)
{
    vector<Teacher>::iterator i;
    for (i = teachers.begin(); i != teachers.end(); i++)
        if ((*i).id == id)
            return *i;

    throw "Argumento invalido.";
}

bool Graph::checkEdge(int id_school, int id_teacher)
{
    Node *v1 = &findSchool(id_school);
    Node *v2 = &findTeacher(id_teacher);

    return (v1->checkEdge(v2));
}

void Graph::addEdge(int id_school, int id_teacher)
{
    Node *v1 = &findSchool(id_school);
    Node *v2 = &findTeacher(id_teacher);
    v1->push_back(v2);
    v2->push_back(v1);
}

void Graph::removeEdge(int, int id_teacher)
{
    if (checkEdge(id_school, id_teacher))
    {
        Node *v1 = &findSchool(id_school);
        Node *v2 = &findTeacher(id_teacher);
        v1->removeEdge(v2);
        v2->removeEdge(v1);
    }
    else
        cout << "Aresta (" << id_school << ", " << id_teacher << ") não existe." << endl;
}

ostream &operator<<(ostream &os, const Graph &graph)
{
    os << "\nSchools:\n";
    for (const School &v : graph.schools)
        os << v;

    os << "\nTeachers:\n";
    for (const Teacher &v : graph.teachers)
        os << v;

    os << endl;
    return os;
}

void Node::push_back(Node *n)
{
    adjacency.push_back(n);
}

void Node::removeEdge(Node *n)
{

    //http://www.cplusplus.com/reference/vector/vector/erase/

    adjacency.erase(remove(adjacency.begin(), adjacency.end(), n), adjacency.end());
}

bool Node::connected()
{
    return (adjacency.size() != 0);
}

int Node::rate()
{
    return adjacency.size();
}

bool Node::checkEdge(Node *n)
{
    for (Node *adj : adjacency)
        if (adj->id == n->id)
            return true;

    return false;
}

School::School(int id, int job1, int job2)
{

    id = id;
    jobs.push_back(job1);
    jobs.push_back(job2);

    current_job = 0;
}

School::School(int id, int job1 {
    id = id;
    jobs.push_back(job1);
    current_job = 0;
}

void School::nextVacancie() {
    if (current_job == 1)
    {
        current_job = 0;
    }
    else
    {
        current_job++;
    }
}

ostream& operator <<(ostream& os, const School& school) {
    os << "[E" << school.id << "] - vagas: " << school.jobs.size() << ", requerindo ";
    for (int habt : school.jobs)
        os << "(" << habt << ")";

    os << " habilitações respectivamente." << endl;
    return os;
}

Teacher::Teacher(int id, int skills, int c1, int c2, int c3, int c4) {
    id = id;
    skills = skills;
    choices.push_back(c1);
    choices.push_back(c2);
    choices.push_back(c3);
    choices.push_back(c4);

    //start as not hired
    hired = false;
}

ostream& operator <<(ostream& os, const Teacher& teacher) {
    os << "[P" << teacher.id << "] - habilitações: " << teacher.skills << ", preferências: ";
    for (int esc : teacher.choices)
        os << "(" << esc << ")";

    os << endl;
    return os;
}
