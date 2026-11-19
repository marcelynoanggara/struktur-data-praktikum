#include "dll_driver.h"

void createList(List &L) {
    first(L) = nil;
    last(L) = nil;
}

bool isEmpty(List L) {
    return first(L) == nil && last(L) == nil;
}

address allocate(infotype data) {
    address P = new ElmList;
    info(P) = data;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (isEmpty(L)) {
        P = nil;
    } else if (first(L) == last(L)) {
        P = first(L);
        first(L) = nil;
        last(L) = nil;
        next(P) = nil;
        prev(P) = nil;
    } else {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = nil;
        next(P) = nil;
        prev(P) = nil;
    }
}

void deleteLast(List &L, address &P) {
    if (isEmpty(L)) {
        P = nil;
    } else if (first(L) == last(L)) {
        P = last(L);
        first(L) = nil;
        last(L) = nil;
        next(P) = nil;
        prev(P) = nil;
    } else {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = nil;
        next(P) = nil;
        prev(P) = nil;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }
    address P = first(L);
    int nomor = 1;
    while (P != nil) {
        cout << nomor << ". Nama Driver : " << info(P).nama
             << " | Rating : " << fixed << setprecision(2) << info(P).rating << endl;
        P = next(P);
        nomor++;
    }
}

void resetData(List &L) {
    if (isEmpty(L)) {
        cout << "List kosong, tidak ada data yang dikeluarkan." << endl;
        return;
    }
    address P;
    float totalRating = 0.0;
    int jumlahDriver = 0;
    while (!isEmpty(L)) {
        deleteFirst(L, P);
        cout << "Keluar -> Nama Driver : " << info(P).nama
             << " | Rating : " << fixed << setprecision(2) << info(P).rating << endl;
        totalRating += info(P).rating;
        jumlahDriver++;
        delete P;
    }
    float rataRata = totalRating / jumlahDriver;
    cout << "Status List : Kosong" << endl;
    cout << "Rata-rata rating driver : " << fixed << setprecision(2) << rataRata << endl;
}

void splitData(List &L, List &listA, List &listB, float N) {
    createList(listA);
    createList(listB);
    address P;
    while (!isEmpty(L)) {
        deleteFirst(L, P);
        if (info(P).rating < N) {
            insertLast(listA, P);
        } else {
            insertLast(listB, P);
        }
    }
}
