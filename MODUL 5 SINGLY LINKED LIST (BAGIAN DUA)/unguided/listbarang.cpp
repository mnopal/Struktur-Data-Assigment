#include "listBarang.h"
#include <iomanip>

// Cek kosong
bool isEmpty(List L) {
    return (L.first == NULL);
}

// Buat list
void createList(List &L) {
    L.first = NULL;
}

// Alokasi node
address alokasi(string nama, int stok, float harga) {
    address P = new Node;
    P->info.nama = nama;
    P->info.stok = stok;
    P->info.harga = harga;
    P->next = NULL;
    return P;
}

// Dealokasi
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Insert awal
void insertAwal(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// Insert akhir
void insertAkhir(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

// Insert setelah
void insertSetelah(List &L, address prev, address P) {
    if (prev != NULL) {
        P->next = prev->next;
        prev->next = P;
    }
}

// Delete awal
void deleteAwal(List &L) {
    if (!isEmpty(L)) {
        address P = L.first;
        L.first = P->next;
        P->next = NULL;
        dealokasi(P);
    }
}

// Delete akhir
void deleteAkhir(List &L) {
    if (!isEmpty(L)) {
        if (L.first->next == NULL) {
            dealokasi(L.first);
            L.first = NULL;
        } else {
            address Q = L.first;
            address prev = NULL;
            while (Q->next != NULL) {
                prev = Q;
                Q = Q->next;
            }
            prev->next = NULL;
            dealokasi(Q);
        }
    }
}

// Delete setelah
void deleteSetelah(List &L, address prev) {
    if (prev != NULL && prev->next != NULL) {
        address P = prev->next;
        prev->next = P->next;
        P->next = NULL;
        dealokasi(P);
    }
}

// Update awal
void updateAwal(List L) {
    if (!isEmpty(L)) {
        cout << "Update node pertama\n";
        cout << "Nama: "; cin >> L.first->info.nama;
        cout << "Stok: "; cin >> L.first->info.stok;
        cout << "Harga: "; cin >> L.first->info.harga;
    }
}

// Update akhir
void updateAkhir(List L) {
    if (!isEmpty(L)) {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        cout << "Update node terakhir\n";
        cout << "Nama: "; cin >> Q->info.nama;
        cout << "Stok: "; cin >> Q->info.stok;
        cout << "Harga: "; cin >> Q->info.harga;
    }
}

// Update setelah
void updateSetelah(List L, address prev) {
    if (prev != NULL && prev->next != NULL) {
        address Q = prev->next;
        cout << "Update node setelah " << prev->info.nama << "\n";
        cout << "Nama: "; cin >> Q->info.nama;
        cout << "Stok: "; cin >> Q->info.stok;
        cout << "Harga: "; cin >> Q->info.harga;
    }
}

// Print
void tampilList(List L) {
    cout << fixed << setprecision(0); // supaya tidak pakai notasi ilmiah
    address P = L.first;
    while (P != NULL) {
        cout << "Nama: " << P->info.nama
             << ", Stok: " << P->info.stok
             << ", Harga: " << P->info.harga << endl;
        P = P->next;
    }
}


// Hitung node
int jumlahNode(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

// Cari berdasarkan nama
void cariNama(List L, string nama) {
    address P = L.first;
    int pos = 0;
    bool ketemu = false;
    while (P != NULL) {
        pos++;
        if (P->info.nama == nama) {
            cout << "Data ditemukan di posisi ke-" << pos << endl;
            ketemu = true;
            break;
        }
        P = P->next;
    }
    if (!ketemu) {
        cout << "Data tidak ditemukan\n";
    }
}

// Cari berdasarkan alamat
void cariAlamat(List L, address Ptarget) {
    address P = L.first;
    int pos = 0;
    bool ketemu = false;
    while (P != NULL) {
        pos++;
        if (P == Ptarget) {
            cout << "Node ditemukan di posisi ke-" << pos << endl;
            ketemu = true;
            break;
        }
        P = P->next;
    }
    if (!ketemu) {
        cout << "Alamat node tidak ditemukan\n";
    }
}

// Cari range harga
void cariRangeHarga(List L, float min, float max) {
    address P = L.first;
    bool ketemu = false;
    while (P != NULL) {
        if (P->info.harga >= min && P->info.harga <= max) {
            cout << "Nama: " << P->info.nama 
                 << ", Harga: " << P->info.harga << endl;
            ketemu = true;
        }
        P = P->next;
    }
    if (!ketemu) {
        cout << "Tidak ada data dalam range harga\n";
    }
}
