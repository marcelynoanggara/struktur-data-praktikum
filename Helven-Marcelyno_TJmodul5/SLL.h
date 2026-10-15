#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

const int S = 50;

struct masakan {
    int nomor;
    string nama;
    int sisaPorsi;
};

typedef masakan infotype;
typedef struct ElmtMsk *address;

struct ElmtMsk {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createNewList(List &L);
void insertLast(List &L, address p);
void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
void deleteAfter(List &L, address prec, address &P);

bool empty(List mList);
infotype newMasakan(int no, string nama);
address newElementList(infotype m);
void addNElementList(List &mList, int N);
void showAllFood(List mList);
void showAvailableFood(List mList);
address findMinRemaining(List mList);
void showBestSeller(List mList);
void deleteAllSoldOut(List &mList);
void transaction(List &L, int noMasakan, int porsi);

#endif // SLL_H_INCLUDED
