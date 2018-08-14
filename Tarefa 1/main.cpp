#include <iostream>
#include "Automato.h"

using namespace std;

void teste(string str, int n) {
    cout << str[n] << endl;
    if(n != 0)
        teste(str, --n);
    cout << str[n] << endl;

}

int main() {

    Automato automato(8, 0, {4});
    automato.addConnection(0, 1, Function('a', {}, {'A'}));
    automato.addConnection(0, 5, Function('a', {}, {}));

    automato.addConnection(1, 1, Function('a', {}, {'A'}));
    automato.addConnection(1, 2, Function('b', {}, {}));
    automato.addConnection(2, 2, Function('b', {}, {}));
    automato.addConnection(2, 3, Function('c', {'A'}, {}));
    automato.addConnection(3, 3, Function('c', {'A'}, {}));
    automato.addConnection(3, 4, Function('$', {'$'}, {}));

    automato.addConnection(5, 5, Function('a', {}, {}));
    automato.addConnection(5, 6, Function('b', {}, {'B'}));
    automato.addConnection(6, 6, Function('b', {}, {'B'}));
    automato.addConnection(6, 7, Function('c', {'B'}, {}));
    automato.addConnection(7, 7, Function('c', {'B'}, {}));
    automato.addConnection(7, 4, Function('$', {'$'}, {}));

    cout << (automato.run("abbbc$") ? "True" : "False") << endl;
    cout << (automato.run("aaaabcccc$") ? "True" : "False") << endl;
    cout << (automato.run("abcccc$") ? "True" : "False") << endl;
    cout << (automato.run("abbbc$") ? "True" : "False") << endl;
    return 0;
}