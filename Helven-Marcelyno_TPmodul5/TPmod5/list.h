#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;
typedef int infotype;
typedef struct element *address;

struct element {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList_108092500012(List &L);
address allocate_108092500012(infotype x);
void insertLast_108092500012(List &L, address P);
void showAllData_108092500012(List L);
address findMin_108092500012(List L);
void insertMiddle_108092500012(List &L, infotype value);

#endif
