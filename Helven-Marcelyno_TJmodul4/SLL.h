#ifndef SLL_H
#define SLL_H

#include <iostream>
#include <string>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef string infotype;
typedef struct element *adr;

struct element {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void createList(List &L);
adr alokasi(infotype data);
void insertFirst(List &L, adr P);
void insertLast(List &L, adr P);
void insertAfter(List &L, adr Prec, adr P);
void deleteFirst(List &L, adr &P);
void deleteLast(List &L, adr &P);
void deleteAfter(List &L, adr Prec, adr &P);
void show(List L);
adr findInfo(List L, infotype x);

#endif
