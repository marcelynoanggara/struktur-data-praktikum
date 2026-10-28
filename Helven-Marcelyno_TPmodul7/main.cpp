#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stack S;
    createStack(S);

    push(S, 'I');
    push(S, 'R');
    push(S, 'I');
    push(S, 'D');
    push(S, 'A');
    push(S, 'Y');
    push(S, 'A');
    push(S, 'C');
    push(S, 'R');
    push(S, 'E');
    push(S, 'P');

    printInfo(S);

    for (int i = 0; i < 7; i++) {
        pop(S);
    }

    printInfo(S);

    return 0;
}
