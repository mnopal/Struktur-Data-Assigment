#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// PROTOTYPE
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address p);
void printInfo(List L);
void insertFirst(List &L, address p);

#endif
