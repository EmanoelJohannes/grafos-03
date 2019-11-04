#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include "../include/graph.h"

#define INPUT_FILE "../bin/graph.txt"

#define MAX_LENGTH 150

using namespace std;

int main()
{
    Graph graph;

    string path = INPUT_FILE;

    FILE *file = fopen((char *)path.c_str(), "r");

    if (!file)
    {

        exit(0);
    }

    else
    {

        char line[MAX_LENGTH];

        int id, tSkills, tPref1, tPref2, tPref3, tPref4;

        int sV1, sV2;

        while (fgets(line, MAX_LENGTH, file))
        {

            if (strstr(line, "(P"))
            {

                sscanf(line, "(P%d, %d): (E%d, E%d, E%d, E%d)", &id, &tSkills, &tPref1, &tPref2, &tPref3, &tPref4);

                Teacher teacher;

                teacher.id = id;
                teacher.skills = tSkills;
                teacher.schools.push_back(tPref1);
                teacher.schools.push_back(tPref2);
                teacher.schools.push_back(tPref3);
                teacher.schools.push_back(tPref4);

                graph.insertTeacher(teacher);
                // cout << "Professor: " << id << " " << tSkills << "\nEscolas: " << tPref1 << " " << tPref2 << endl
                //      << endl;
            }

            else if (strstr(line, "(E"))
            {

                sscanf(line, "(E%d): (%d, %d)", &id, &sV1, &sV2);

                School school;

                school.id = id;
                school.skills.push_back(sV1);
                school.skills.push_back(sV2);

                graph.insertSchool(school);

                // cout << "Escola: " << id << "\nHabilitacoes: " << sV1 << endl << endl;
            }
        }
    }

    return 0;
}