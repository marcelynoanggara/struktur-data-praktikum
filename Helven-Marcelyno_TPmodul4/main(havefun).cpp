#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    address P;
    infotype digit;

    createList(L);

    cout << "Masukkan NIM perdigit" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << "Digit " << i << ": ";
        cin >> digit;

        P = allocate(digit);
        insertLast(L, P);
    }

    cout << "Isi list: ";
    printInfo(L);

    return 0;
}

