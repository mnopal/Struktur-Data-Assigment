#ifndef LISTBARANG_H
#define LISTBARANG_H

#include <iostream>
using namespace std;

struct Barang {
    string nama;
    int stok;
    float harga;
};

typedef Barang InfoBarang;
typedef struct Node *address;

struct Node {
    InfoBarang info;
    address next;
};

struct List {
    address first;
};

bool isEmpty(List L);
void createList(List &L);

address alokasi(string nama, int stok, float harga);
void dealokasi(address &P);

// Insert
void insertAwal(List &L, address P);
void insertAkhir(List &L, address P);
void insertSetelah(List &L, address prev, address P);

// Delete
void deleteAwal(List &L);
void deleteAkhir(List &L);
void deleteSetelah(List &L, address prev);

// Update
void updateAwal(List L);
void updateAkhir(List L);
void updateSetelah(List L, address prev);

// Print
void tampilList(List L);

// Utility
int jumlahNode(List L);

// Searching
void cariNama(List L, string nama);
void cariAlamat(List L, address P);
void cariRangeHarga(List L, float min, float max);

#endif
