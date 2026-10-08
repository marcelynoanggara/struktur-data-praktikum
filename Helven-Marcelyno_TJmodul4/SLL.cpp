#include "SLL.h"

void createList(List &L) {
    first(L) = NULL;
}

adr alokasi(infotype data) {
    adr P = new element;
    info(P) = data;
    next(P) = NULL;
    return P;
}

void insertFirst(List &L, adr P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, adr P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(List &L, adr Prec, adr P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirst(List &L, adr &P) {
    if (first(L) != NULL) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List &L, adr &P) {
    if (first(L) != NULL) {
        if (next(first(L)) == NULL) {
            P = first(L);
            first(L) = NULL;
        } else {
            adr Q = first(L);
            while (next(next(Q)) != NULL) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
}

void deleteAfter(List &L, adr Prec, adr &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void show(List L) {
    if (first(L) == NULL) {
        cout << "Daftar produk kosong";
    } else {
        adr P = first(L);
        while (P != NULL) {
            cout << info(P);
            if (next(P) != NULL) cout << ", ";
            P = next(P);
        }
    }
}

adr findInfo(List L, infotype x) {
    adr P = first(L);
    while (P != NULL && info(P) != x) {
        P = next(P);
    }
    return P;
}
