#include "../headers/graph.h"
#include <vector>
#include <exception>
#include <iterator>
#include <iostream>

using namespace std;

Graph::Graph() {}

void Graph::addNode(School e)
{
	if (!checkSchool(e.id))
		escolas.push_back(e);
	else
		cout << "School [E" << e.id << "] já existe no grafo.";
}

void Graph::addNode(Teacher p)
{
	if (!checkTeacher(p.id))
		profs.push_back(p);
	else
		cout << "Teacher [P" << p.id << "] já existe no grafo.";
}

bool Graph::checkSchool(int id)
{
	vector<School>::iterator it;
	for (it = escolas.begin(); it != escolas.end(); it++)
		if ((*it).id == id)
			return true;

	return false;
}

bool Graph::checkTeacher(int id)
{
	vector<Teacher>::iterator it;
	for (it = profs.begin(); it != profs.end(); it++)
		if ((*it).id == id)
			return true;

	return false;
}

Node &Graph::findSchool(int id)
{
	vector<School>::iterator it;
	for (it = escolas.begin(); it != escolas.end(); it++)
		if ((*it).id == id)
			return *it;

	throw "Argumento invalido.";
}

Node &Graph::findTeacher(int id)
{
	vector<Teacher>::iterator it;
	for (it = profs.begin(); it != profs.end(); it++)
		if ((*it).id == id)
			return *it;

	throw "Argumento invalido.";
}

bool Graph::checkEdge(int id_esc, int id_prof)
{
	Node *v1 = &findSchool(id_esc);
	Node *v2 = &findTeacher(id_prof);

	return (v1->checkEdge(v2));
}

void Graph::addEdge(int id_esc, int id_prof)
{
	Node *v1 = &findSchool(id_esc);
	Node *v2 = &findTeacher(id_prof);
	v1->push_back(v2);
	v2->push_back(v1);
}

void Graph::removeEdge(int id_esc, int id_prof)
{
	if (checkEdge(id_esc, id_prof))
	{
		Node *v1 = &findSchool(id_esc);
		Node *v2 = &findTeacher(id_prof);
		v1->removeEdge(v2);
		v2->removeEdge(v1);
	}
	else
		cout << "Aresta (" << id_esc << ", " << id_prof << ") não existe." << endl;
}

ostream &operator<<(ostream &os, const Graph &grafo)
{
	os << "\nESCOLAS:\n";
	for (const School &v : grafo.escolas)
		os << v;

	os << "\nPROFESSORES:\n";
	for (const Teacher &v : grafo.profs)
		os << v;

	os << endl;
	return os;
}
