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

    while(true) {
      string entry;
      cin >> entry;
      cout << (automato.run(entry) ? "True" : "False") << endl;
    }
    return 0;
}
