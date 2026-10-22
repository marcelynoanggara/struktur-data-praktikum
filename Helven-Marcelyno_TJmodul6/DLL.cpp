#include "DLL.h"

void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address createElemen(infotype dataBaru) {
    address P = new elmList;
    if (P != NULL) {
        P->info = dataBaru;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void insertAfter(address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        if (Prec->next != NULL) {
            Prec->next->prev = P;
        }
        Prec->next = P;
        P->prev = Prec;
    }
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P != NULL) {
        if (L.First->next == NULL) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = L.First->next;
            L.First->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P != NULL) {
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

void printList(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info.title << " " << P->info.url << " " << P->info.timestamp << " " << P->info.visitcount << endl;
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertAscending(List &L, address P) {
    if (L.First == NULL) {
        insertFirst(L, P);
    } else if (P->info.visitcount <= L.First->info.visitcount) {
        insertFirst(L, P);
    } else {
        address Prec = L.First;
        while (Prec->next != NULL && Prec->next->info.visitcount <= P->info.visitcount) {
            Prec = Prec->next;
        }
        if (Prec->next == NULL) {
            insertLast(L, P);
        } else {
            insertAfter(Prec, P);
        }
    }
}

bool findElemen(List L, string X) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.title == X) {
            return true;
        }
        P = P->next;
    }
    return false;
}

int moreThanOnce(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        if (P->info.visitcount > 1) {
            count++;
        }
        P = P->next;
    }
    return count;
}
