#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct history {
    string title;
    string url;
    string timestamp;
    int visitcount;
};

typedef history infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void createList(List &L);
address createElemen(infotype dataBaru);
void insertLast(List &L, address P);
void insertAfter(address Prec, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void printList(List L);

void insertFirst(List &L, address P);
void insertAscending(List &L, address P);
bool findElemen(List L, string X);
int moreThanOnce(List L);

#endif
