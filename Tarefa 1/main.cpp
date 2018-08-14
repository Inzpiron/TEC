#include <iostream>
#include "Automato.h"

using namespace std;

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


    Automato automato1(3, 0, {2});
    automato1.addConnection(0, 0, Function('a', {}, {'A','A', 'A'}));
    automato1.addConnection(0, 1, Function('b', {'A','A'}, {}));
    automato1.addConnection(1, 1, Function('b', {'A','A'}, {}));
    automato1.addConnection(1, 2, Function('$', {'$'}, {}));

    while(true) {
      string entry;
      cin >> entry;
      cout << (automato1.run(entry) ? "True" : "False") << endl << endl;
    }
    return 0;
}
