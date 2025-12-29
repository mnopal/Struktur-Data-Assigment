#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
typedef bool boolean;

/* tipe info */
typedef int infotypeanak;
typedef int infotypeinduk;

/* pointer address */
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* struktur elemen anak */
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

/* struktur list anak */
struct listanak {
    address_anak first;
    address_anak last;
};

/* struktur elemen induk */
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

/* struktur list induk */
struct listinduk {
    address first;
    address last;
};

/********* pengecekan *********/
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

/********* pembuatan list *********/
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/********* manajemen memori *********/
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

/********* pencarian *********/
address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak L, infotypeanak X);

/********* penambahan elemen *********/
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);

void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);

/********* penghapusan elemen *********/
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);

void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);

/********* proses list *********/
void printInfo(listinduk L);
void printInfoAnak(listanak L);

int nbList(listinduk L);
int nbListAnak(listanak L);

#endif
