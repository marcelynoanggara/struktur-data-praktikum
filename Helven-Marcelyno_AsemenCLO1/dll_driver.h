#ifndef DLL_DRIVER_H
#define DLL_DRIVER_H
#include <iostream>
#include <string>
#include <iomanip>
#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nil nullptr

using namespace std;

struct Driver {
    string nama;
    float rating;
};

typedef Driver infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
bool isEmpty(List L);
address allocate(infotype data);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void printInfo(List L);
void resetData(List &L);
void splitData(List &L, List &listA, List &listB, float N);

#endif
