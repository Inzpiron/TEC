//
// Created by leonardo on 13/08/18.
//

#include "Automato.h"

Function::Function(char f1, vector<char> f2, vector<char> f3) : f1(f1), f2(f2), f3(f3) {}

Automato::Automato(int nv, int vi, std::vector<int> vf) {
    this->listaAdj = AdjType(nv);
    vfinais = new bool[nv]{false};

    this->startState = vi;

    for (auto i : vf) {
        this->vfinais[i] = true;
    }
}

Automato::Automato() {}

void Automato::addConnection(int v1, int v2, Function f) {
    this->listaAdj[v1].push_back({v2, f});
}

bool Automato::run(string entry){
    this->stateStoped = -1;
    if(!entry.empty())
      entry.push_back('$');
      
    runEntry(this->startState, entry);

    if(this->vfinais[this->stateStoped])
        return true;


    return false;

}

void Automato::runEntry(int i, std::string entry) {
    if(entry.empty() && this->pilha.empty() && vfinais[i]) {
        stateStoped = i;
    }

    for(int j = 0; j < this->listaAdj[i].size(); j++) {
        //cout << i << " " << entry << endl;
        std::pair<int, Function> u = listaAdj[i][j];

        if (u.second.f1 == entry[0]) {
            bool check = false;

            stack<char> mirror = this->pilha;
            if(u.second.f2.size() <= this->pilha.size()) {
                int ii;
                for (ii = 0; ii < u.second.f2.size(); ii++) {
                    if (u.second.f2[ii] == mirror.top())
                        mirror.pop();
                    else
                        break;
                }

                if (ii == u.second.f2.size())
                    check = true;
            }

            if(u.second.f2.size() == 1) {
                if(pilha.empty() && u.second.f2[0] == '$')
                    check = true;
            }

            string entry0 = entry;
            if (check || (u.second.f2.empty())) {
                if(entry0.size() >= 1)
                    entry0.erase(entry0.begin());

                if(!u.second.f2.empty() && this->pilha.size() >= 1) {
                    if(this->pilha.top() != '$') {
                        for(int ii = 0; ii < u.second.f2.size(); ii++)
                            this->pilha.pop();
                    }
                }

                for(auto c : u.second.f3) {
                    this->pilha.push(c);
                }

                runEntry(u.first, entry0);
            }
        }
    }
}
