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


		/*
		* Finds a school by id in the school list, and returns the school id if found.
		*
		* @param values: id (school id).
		* @return school id if found
		*/
		int findSchool(int id);


		/*
		* Insert a new teacher inside the teachers vector.
		*
		* @param values: node type Teacher.
		*/
    void insertTeacher(Teacher v);


		/*
		* Insert a new school inside the schools vector.
		*
		* @param values: node type School.
		*/
		void insertSchool(School v);


		/*
		* Checks if the school and teacher id's are valid, and adds an edge between them.
		*
		* @param values id.
		* @return school id if found
		*/
    void insertEdge(int id_school, int id_teacher);

};

#endif