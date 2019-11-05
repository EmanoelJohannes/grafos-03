#include "node.h"
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
public:
	vector<School> escolas;
	vector<Teacher> profs;

	Graph();

	void addNode(School v);

	void addNode(Teacher v);

	bool checkSchool(int id);

	bool checkTeacher(int id);

	Node &findSchool(int id);

	Node &findTeacher(int id);

	bool checkEdge(int id_esc, int id_prof);

	void addEdge(int id_esc, int id_prof);

	void removeEdge(int id_esc, int id_prof);

	friend ostream &operator<<(ostream &os, const Graph &grafo);
};
