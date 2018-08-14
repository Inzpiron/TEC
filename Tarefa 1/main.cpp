#include <iostream>
#include <vector>
#include "Automato.h"

using namespace std;

int main(int argc, char ** argv) {
    Automato automato(8, 0, {4});
    automato.debugOn();
    automato.addConnection(0, 1, Function('a', {}, {'A'}));
    automato.addConnection(0, 5, Function('a', {}, {}));

    automato.addConnection(1, 1, Function('a', {}, {'A'}));
    automato.addConnection(1, 2, Function('b', {}, {}));
    automato.addConnection(2, 2, Function('b', {}, {}));
    automato.addConnection(2, 3, Function('c', {'A'}, {}));
    automato.addConnection(3, 3, Function('c', {'A'}, {}));
    automato.addConnection(3, 4, Function('$', {'?'}, {}));

    automato.addConnection(5, 5, Function('a', {}, {}));
    automato.addConnection(5, 6, Function('b', {}, {'B'}));
    automato.addConnection(6, 6, Function('b', {}, {'B'}));
    automato.addConnection(6, 7, Function('c', {'B'}, {}));
    automato.addConnection(7, 7, Function('c', {'B'}i, {}));
    automato.addConnection(7, 4, Function('$', {'?'}, {}));


    for(int i = 1; i < argc; i++) {
        cout << argv[i] << endl;
        cout << automato.run(string(argv[i])) << endl << endl;
    }
    return 0;
}
