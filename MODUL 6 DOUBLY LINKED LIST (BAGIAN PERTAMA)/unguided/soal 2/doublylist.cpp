#include "doublylist.h"
#include <iostream>
using namespace std;

/* Membuat list kosong */
void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

/* Alokasi node */
address alokasi(kendaraan x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

/* Dealokasi */
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

/* Cek nomor polisi sudah ada atau belum */
bool cekNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

/* Mencari elemen berdasarkan nomor polisi */
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;  // Mengembalikan address jika ditemukan
        }
        P = P->next;
    }
    return NULL;  // Mengembalikan NULL jika tidak ditemukan
}

/* Insert di akhir list */
void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

/* Menampilkan isi list dari belakang */
void printInfo(List L) {
    address P = L.Last;
    cout << "\nDATA LIST 1\n";
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl << endl;
        P = P->prev;
    }
}

/* Menampilkan isi list dari depan (opsional) */
void printForward(List L) {
    address P = L.First;
    cout << "\nDATA LIST (DARI DEPAN)\n";
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl << endl;
        P = P->next;
    }
}

/* Menghapus elemen berdasarkan nomor polisi */
void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    
    if (P == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }
    
    if (P == L.First && P == L.Last) { // Hanya satu elemen
        L.First = NULL;
        L.Last = NULL;
    } else if (P == L.First) { // Elemen pertama
        L.First = P->next;
        L.First->prev = NULL;
    } else if (P == L.Last) { // Elemen terakhir
        L.Last = P->prev;
        L.Last->next = NULL;
    } else { // Elemen di tengah
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }
    
    dealokasi(P);
    cout << "Data dengan nopol " << nopol << " berhasil dihapus!" << endl;
}

/* Menghitung jumlah elemen dalam list */
int countElm(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}