#include "Doublylist.h"

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
