#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	// A unique code for teacher or school
	int id;

	vector<Node *> adjacency;

	Node();

	void push_back(Node *v);
	void removeEdge(Node *v);
	bool checkEdge(Node *v);
	bool connected();
	int rate();
};

class School : public Node
{
public:
	vector<int> jobs;
	int current_job;
	int job1, job2;
	School(int _id, int _job1);
	School(int _id, int _job1, int _job2);
	void nextJob();

	friend ostream &operator<<(ostream &os, const School &school);
};

class Teacher : public Node
{
public:
	int skills;
	vector<int> choices;

	Teacher(int _id, int _skills, int s1, int s2, int s3, int s4);

	friend ostream &operator<<(ostream &os, const Teacher &teacher);
};
