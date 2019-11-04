#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include "../include/graph.h"

#define INPUT_FILE "../bin/graph.txt"

using namespace std;

int main() {

    Graph graph;

    string line;

    ifstream file(INPUT_FILE);

    string codigo, preferencias;
    int habilitacoes;

    while (getline(file, line))
    {
        char a1, a2, a3, a4;
        sscanf(line, "&s &s &s &s", a1, a2, a3, a4);

        cout << a1 << a2 << a3 << a4 << endl;
        // cout << line << endl;
        // for (char& c : line ){
        //   if (c == '/'){            
        //     break;
        //   }

        //   if (c == 'P'){

        //     cout << line << endl;
            
        //     file >> codigo >> habilitacoes;

        //     // for (char& preferenciasChar : line){
        //     //   cout << preferenciasChar;
        //     // }

        //     // cout << endl << endl;

        //     string prof = codigo.substr(codigo.find('P')+1, codigo.find(",")-1);
        //     cout << "Codigo: " << prof << "\nHabilitacaoes: " << habilitacoes;
        //   }
          // cout << c; 
    }
    
    return 0;
}