#include <string>
#include <vector>

#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;

struct Teacher {
	int id;
	int skills;
	vector<struct School*> schools;
};

struct School {
	int id;
	vector<int> skills;
};

class Graph
{
    
	vector<struct Teacher> teachers;
  vector<struct School> schools;

public:
    // void DFS(Node &v);

    // void topologicalSort_DFS(Node &v, stack<struct Node> &pilha);

    // void topologicalSort();

		int findSchool(int id);

    void insertTeacher(Teacher v);

		void insertSchool(School v);

    void insertEdge(int id_school, int id_teacher);

};

#endif