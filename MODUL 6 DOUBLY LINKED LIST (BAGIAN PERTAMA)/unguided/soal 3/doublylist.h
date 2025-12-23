#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// Deklarasi fungsi
void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
bool cekNopol(List L, string nopol);
address findElm(List L, string nopol);
void insertLast(List &L, address P);
void printInfo(List L);
void printListWithWarna(List L); 
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
bool deleteByNopol(List &L, string nopol);

#endif