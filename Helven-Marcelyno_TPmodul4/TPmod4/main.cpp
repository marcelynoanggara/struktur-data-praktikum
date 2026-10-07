#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    address P;
    createList(L);

    P = allocate(0);

    insertFirst(L, P);

    P = allocate(1);
    insertFirst(L, P);

    P = allocate(2);
    insertFirst(L, P);

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}
