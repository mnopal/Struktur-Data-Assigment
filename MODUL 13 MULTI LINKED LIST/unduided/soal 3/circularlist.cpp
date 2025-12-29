#include "circularlist.h"
#include <iomanip>

// Procedure CreateList: Membuat list kosong
void createList(List &L) {
    L.First = NULL;
}

// Function alokasi: Mengalokasikan elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

// Procedure dealokasi: Membebaskan memori elemen
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Procedure insertFirst: Menyisipkan elemen di awal list
void insertFirst(List &L, address P) {
    if (L.First == NULL) { // List kosong
        L.First = P;
        P->next = P; // Circular: menunjuk ke dirinya sendiri
    } else {
        // Cari elemen terakhir
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        
        P->next = L.First;
        L.First = P;
        last->next = P; // Update next dari elemen terakhir
    }
}

// Procedure insertAfter: Menyisipkan elemen setelah Prec
void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
        
        // Jika Prec adalah elemen terakhir, maka P menjadi elemen terakhir
        // Tidak perlu update karena sudah circular
    }
}

// Procedure insertLast: Menyisipkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == NULL) { // List kosong
        L.First = P;
        P->next = P;
    } else {
        // Cari elemen terakhir
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        
        last->next = P;
        P->next = L.First; // Circular: menunjuk ke elemen pertama
    }
}

// Procedure deleteFirst: Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        
        if (L.First->next == L.First) { // Hanya satu elemen
            L.First = NULL;
        } else {
            // Cari elemen terakhir
            address last = L.First;
            while (last->next != L.First) {
                last = last->next;
            }
            
            L.First = L.First->next;
            last->next = L.First; // Update next dari elemen terakhir
            P->next = NULL;
        }
    }
}

// Procedure deleteAfter: Menghapus elemen setelah Prec
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

// Procedure deleteLast: Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == L.First) { // Hanya satu elemen
            P = L.First;
            L.First = NULL;
        } else {
            // Cari elemen sebelum terakhir
            address prev = L.First;
            while (prev->next->next != L.First) {
                prev = prev->next;
            }
            
            P = prev->next;
            prev->next = L.First; // Update next dari elemen sebelum terakhir
            P->next = NULL;
        }
    }
}

// Function findElm: Mencari elemen berdasarkan NIM
address findElm(List L, infotype x) {
    if (L.First == NULL) {
        return NULL;
    }
    
    address P = L.First;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);
    
    return NULL;
}

// Procedure printInfo: Mencetak semua elemen dalam list
void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    
    address P = L.First;
    int count = 1;
    
    cout << "Isi List:" << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "Elemen ke-" << count << ":" << endl;
        cout << "Nama           : " << P->info.nama << endl;
        cout << "NIM            : " << P->info.nim << endl;
        cout << "Jenis Kelamin  : " << P->info.jenis_kelamin << endl;
        cout << "IPK            : " << fixed << setprecision(2) << P->info.ipk << endl;
        cout << "----------------------------------------" << endl;
        
        P = P->next;
        count++;
    } while (P != L.First);
    
    cout << "Total elemen: " << count-1 << endl;
    cout << "========================================" << endl;
}