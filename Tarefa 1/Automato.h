//
// Created by leonardo on 13/08/18.
//
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <cstring>
#include <stack>
#include <iostream>

#ifndef CLIONPROJECTS_AUTOMATO_H
#define CLIONPROJECTS_AUTOMATO_H


using namespace std;

struct Function {
    char f1;
    vector<char> f2;
    vector<char> f3;

    Function(char f1, vector<char> f2, vector<char> f3);
};

typedef struct Function Function;
typedef std::vector<std::vector< std::pair<int, struct Function> > > AdjType;

class Automato {
private:
    std::stack<char> pilha;
    bool * vfinais;
    bool debug;
    AdjType listaAdj;
    int startState;
    int stateStoped = -1;
    void runEntry(int i, std::string entry);
    Automato();

public:
    void debugOn();
    void debugOff();
    Automato(int nv, int vi, std::vector<int> vf);
    void addConnection(int v1, int v2, Function f);
    bool run(string entry);
};


#endif //CLIONPROJECTS_AUTOMATO_H
