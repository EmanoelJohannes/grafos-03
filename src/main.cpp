#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include "../headers/graph.h"

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

                graph.addNode(Teacher(id, tSkills, tPref1, tPref2, tPref3, tPref4));


              
            }

            else if (strstr(line, "(E"))
            {

                sscanf(line, "(E%d): (%d, %d)", &id, &sV1, &sV2);

                if (sV2 != 0){
                    graph.addNode(School(id,sV1,sV2));
                } else {
                    graph.addNode(School(id,sV1));
                }
                
            }
        }

        cout << graph;
    }

    return 0;
}