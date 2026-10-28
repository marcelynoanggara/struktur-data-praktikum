#include "stack.h"
#include <iostream>

using namespace std;

void createStack(stack &S) {
    Top(S) = 0;
}

bool isEmpty(stack S) {
    if (Top(S) == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(stack S) {
    if (Top(S) == 15) {
        return true;
    } else {
        return false;
    }
}

void push(stack &S, infotype x) {
    if (isFull(S) == false) {
        Top(S) = Top(S) + 1;
        info(S)[Top(S) - 1] = x;
    }
}

infotype pop(stack &S) {
    infotype x = info(S)[Top(S) - 1];
    Top(S) = Top(S) - 1;
    return x;
}

void printInfo(stack S) {
    for (int i = Top(S); i >= 1; i--) {
        cout << info(S)[i - 1];
    }
    cout << '\n';
}
