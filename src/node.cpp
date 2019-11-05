#include "../headers/node.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

Node::Node() {}

void Node::push_back(Node *v)
{
	adjacency.push_back(v);
}

void Node::removeEdge(Node *v)
{
	adjacency.erase(remove(adjacency.begin(), adjacency.end(), v), adjacency.end());
}

bool Node::checkEdge(Node *v)
{
	for (Node *adj : adjacency)
		if (adj->id == v->id)
			return true;

	return false;
}

bool Node::connected()
{
	return (adjacency.size() != 0);
}

int Node::rate()
{
	return adjacency.size();
}

School::School(int _id, int _job1, int _job2)
{
	id = _id;
	job1 = _job1;
	job2 = _job2;
	jobs.push_back(_job1);
	jobs.push_back(_job2);
	current_job = 0;
}

School::School(int _id, int _job1)
{
	id = _id;
	job1 = _job1; //We have to check this later
	jobs.push_back(_job1);
	current_job = 0;
}

void School::nextJob()
{
	if (current_job == 1)
		current_job = 0;
	else
		current_job++;
}

ostream &operator<<(ostream &os, const School &school)
{
	os << "[E" << school.id << "] - vagas: " << school.jobs.size() << ", Pretende ";
	for (int habt : school.jobs)
		os << "(" << habt << ")";

	os << " habilitações respectivamente." << endl;
	return os;
}

Teacher::Teacher(int _id, int _skills, int s1, int s2, int s3, int s4)
{
	id = _id;
	skills = _skills;
	choices.push_back(s1);
	choices.push_back(s2);
	choices.push_back(s3);
	choices.push_back(s4);
}

ostream &operator<<(ostream &os, const Teacher &teacher)
{
	os << "[P" << teacher.id << "] - habilitações: " << teacher.skills << ", preferências: ";
	for (int esc : teacher.choices)
		os << "(" << esc << ")";

	os << endl;
	return os;
}
