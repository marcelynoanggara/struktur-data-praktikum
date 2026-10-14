#include "list.h"

void createList_108092500012(List &L) {
    L.first = nullptr;
}

address allocate_108092500012(infotype x) {
    address P = new element;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertLast_108092500012(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void showAllData_108092500012(List L) {
    if (L.first == nullptr) {
        cout << "List Kosong." << endl;
    } else {
        address P = L.first;
        while (P != nullptr) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

address findMin_108092500012(List L) {
    if (L.first == nullptr) return nullptr;

    address P = L.first;
    address minAddr = P;

    while (P != nullptr) {
        if (P->info < minAddr->info) {
            minAddr = P;
        }
        P = P->next;
    }
    return minAddr;
}

void insertMiddle_108092500012(List &L, infotype value) {
    address P = allocate_108092500012(value);

    if (L.first == nullptr) {
        L.first = P;
    } else {
        int count = 0;
        address temp = L.first;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        temp = L.first;

        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }
        P->next = temp->next;
        temp->next = P;
    }
}
