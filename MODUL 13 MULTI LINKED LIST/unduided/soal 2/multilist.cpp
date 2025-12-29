#include "multilist.h"
#include <iostream>
using namespace std;

/********* Pengecekan *********/
boolean ListEmpty(listinduk L) {
    return (L.first == Nil);
}

boolean ListEmptyAnak(listanak L) {
    return (L.first == Nil);
}

/********* Create List *********/
void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

/********* Alokasi *********/
address alokasi(infotypeinduk P) {
    address Q = new elemen_list_induk;
    Q->info = P;
    Q->next = Nil;
    Q->prev = Nil;
    CreateListAnak(Q->lanak);
    return Q;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak Q = new elemen_list_anak;
    Q->info = P;
    Q->next = Nil;
    Q->prev = Nil;
    return Q;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

/********* Searching *********/
address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElm(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

/********* Insert Induk *********/
void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

/********* Insert Anak *********/
void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

/********* Print *********/
void printInfo(listinduk L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Induk : " << P->info << " -> Anak : ";
        printInfoAnak(P->lanak);
        cout << endl;
        P = P->next;
    }
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

/********* Count *********/
int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

int nbListAnak(listanak L) {
    int n = 0;
    address_anak P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}
