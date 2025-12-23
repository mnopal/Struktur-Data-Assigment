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
            return P;
        }
        P = P->next;
    }
    return NULL;
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

/* Menampilkan isi list dengan format "Mama" seperti gambar */
void printListWithWarna(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1\n";
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;  // YANG BENAR
        cout << "Tahun        : " << P->info.thnBuat << endl << endl;
        P = P->next;
    }
    cout << "---\n";
}

/* Delete First */
void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
        return;
    }
    
    P = L.First;
    if (L.First == L.Last) { // Hanya satu elemen
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = P->next;
        L.First->prev = NULL;
    }
    P->next = NULL;
}

/* Delete Last */
void deleteLast(List &L, address &P) {
    if (L.Last == NULL) {
        P = NULL;
        return;
    }
    
    P = L.Last;
    if (L.First == L.Last) { // Hanya satu elemen
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.Last = P->prev;
        L.Last->next = NULL;
    }
    P->prev = NULL;
}

/* Delete After */
void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    
    P = Prec->next;
    Prec->next = P->next;
    
    if (P->next != NULL) {
        P->next->prev = Prec;
    } else { // Jika P adalah elemen terakhir
        // Update Last pointer jika diperlukan
    }
    
    P->next = NULL;
    P->prev = NULL;
}

/* Delete berdasarkan nomor polisi (menggabungkan ketiga fungsi di atas) */
bool deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    
    if (P == NULL) {
        return false; // Data tidak ditemukan
    }
    
    if (P == L.First) {
        deleteFirst(L, P);
    } else if (P == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(P->prev, P);
    }
    
    dealokasi(P);
    return true;
}