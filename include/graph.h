#include <string>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <vector>

class Graph
{

public:
	vector<Teacher> teachers;
	vector<School> schools;

	//empity graph
	Graph();

	bool checkSchool(int id);
	bool checkTeacher(int id);
	void addNode(School n);
	void addNode(Teacher n);

	Node &finSchool(int id);
	Node &findTeacher(int id);

	//Check if exists a edge between a teacher and a school
	bool checkEdge(int id_school, int id_teacher);

	//Add an edge between teacher and school
	void addEdge(int id_school, int id_teacher);

	//Remove an edge between teacher and school
	void removeEdge(int id_school, int id_teacher);

	friend ostream &operator<<(ostream &os, const Graph &graph);
};

class Node
{

public:
	//each school or teach has his own ID
	int id;

	vector<Node *> adjacency;

	//empity Node
	Node();

	void push_back(Node *n);

	//aresta
	void removeEdge(Node *n);
	bool checkEdge(Node *n);

	// We can return the "grau" - IDK how to say that in english -
	int rate();

	// Check if this Node is connected.
	bool connected();
};

class Teacher : public Node
{

public:
	//In this project, we just received the skill amount, not any specific skill
	int skills;
	// Each position of our vec receive an school number(id). Ordered by priority
	//
	vector<int> choices;
	bool hired;

	Teacher(int id, int skills, int c1, int c2, int c3, int c4);

	// A external method can access our data, even the  private ones. God bless friend declaration
	friend ostream &operator<<(ostream &os, const Teacher &teacher);
};

class School : public Node
{

public:
	vector<int> jobs;
	vector<Node *> hired = adjacency;
	int current_job;
	School(int id, int job1, int job2);
	School(int id, int job1);

	void nextVacancie();

	bool full;

	friend ostream &operator<<(ostream &os, const School &school);
};
