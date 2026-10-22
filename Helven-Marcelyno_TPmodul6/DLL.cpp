#include "DLL.h"

bool isEmpty(List L) {
    return L.first == NULL && L.last == NULL;
}

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address createNewElmt(infotype X) {
    address P = new elmtList;
    if (P != NULL) {
        P->info = X;
        P->prev = NULL;
        P->next = NULL;
    }
    return P;
}

void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != NULL) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = L.first->next;
            L.first->prev = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        if (P == L.last) {
            L.last = Prec;
            Prec->next = NULL;
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = L.last->prev;
            L.last->next = NULL;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void concat(List L1, List L2, List &L3) {
    createList(L3);
    address P = L1.first;
    while (P != NULL) {
        address baru = createNewElmt(P->info);
        insertLast(L3, baru);
        P = P->next;
    }
    P = L2.first;
    while (P != NULL) {
        address baru = createNewElmt(P->info);
        insertLast(L3, baru);
        P = P->next;
    }
}

address findLagu(string Judul, List L) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.judulLagu == Judul) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void removeLagu(string Judul, List &L) {
    address P = findLagu(Judul, L);
    if (P != NULL) {
        address temp;
        if (P == L.first) {
            deleteFirst(L, temp);
        } else if (P == L.last) {
            deleteLast(L, temp);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, temp);
        }
        delete temp;
    }
}

void printList(List L) {
    address P = L.first;
    if (isEmpty(L)) {
        cout << "List Kosong\n";
    } else {
        while (P != NULL) {
            cout << "Band: " << P->info.namaBand << " | Lagu: " << P->info.judulLagu << "\n";
            P = P->next;
        }
    }
    cout << "\n";
}
