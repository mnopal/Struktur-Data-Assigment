#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

/* infotype */
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

/* address */
typedef struct ElmList *address;

/* Elemen List */
struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

/* List */
struct List {
    address First;
    address Last;
};

/* Prototype ADT */
void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool cekNopol(List L, string nopol);

#endif
