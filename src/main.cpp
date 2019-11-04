#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include "../include/graph.h"

#define INPUT_FILE "../bin/graph.txt"

using namespace std;

int main()
{

    //Read our file
    string path = INPUT_FILE;
    FILE *file = fopen((char *)path.c_str(), "r");

    //After removing useless things (not formatted), we just wave 150 lines
    int id, tSkills, tPref1, tPref2, tPref3, tPref4;
    char line[150];

    int sV1, sV2;

    while (fgets(line, 150, file))
    {

        //(P1, 3): (E10, E20, E1, E3)
        //(E10):(1):(2)

        //Lets check if line starts with (P
        if (strstr(line, "(P"))
        {

            sscanf(line, "(P%d, %d): (E%d, E%d, E%d, E%d)", &id, &tSkills, &tPref1, &tPref2, &tPref3, &tPref4);

            cout << "Professor : " << id << " " << tSkills << "\nEscolas: " << tPref1 << " " << tPref2 << endl
                 << endl;
        }

        //Lets check if line starts with (E
        else if (strstr(line, "(E"))
        {

            sscanf(line, "(E%d): (%d, %d)", &id, &sV1, &sV2);
            cout << "Escola: " << id << "\nHabilitacoes: " << sV1 << endl;
        }
    }

    return 0;
}