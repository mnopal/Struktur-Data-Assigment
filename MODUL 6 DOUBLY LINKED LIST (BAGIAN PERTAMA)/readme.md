 <h1 align="center">Laporan Praktikum Modul Singly Linked List (bagian pertama) </h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

Doubly Linked list adalah linked list yang masing – masing elemen nya memiliki 2 successor, yaitu
successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
sesudahnya (next)

## Guided 

### 1. DLL_playlist.cpp

```C++
#include "DLL_playlist.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocate(address P) {
    delete P;
}

float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != nullptr) {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = P;
        else
            L.tail = P;

        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != nullptr) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;

            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = P->next;
            L.head->prev = nullptr;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = P->prev;
            L.tail->next = nullptr;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Q;
        else
            L.tail = Q;

        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;
        S = P->info;

        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            deallocate(P);
        }
    }
}

void updateAtPosition(List &L, int posisi) {
    int idx = 1;
    address P = L.head;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;

        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        cout << idx << ". "
             << P->info.Title << " | " << P->info.Artist
             << " | " << P->info.DurationSec << "s | PC: "
             << P->info.PlayCount << " | Rating: "
             << P->info.Rating << " | PopularityScore: "
             << pop << endl;

        P = P->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int idx = 1;

    cout << "\nHasil searching PopularityScore in [" 
         << minScore << ", " << maxScore << "]\n";

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". " << P->info.Title 
                 << " | PopularityScore: " << pop << endl;
        }

        P = P->next;
        idx++;
    }
}
```

### 2. DLL_playlist.h
```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;    
};

typedef struct Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

float getPopularityScore(Song S);

#endif
```

### 3. dll_hapus.cpp
```C++
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
}
```

### 4. dll_insert.cpp
```c++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist


struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};


struct List { 
    address first; 
    address last; 
}; 


void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 


void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 


void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}


address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 


void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}


int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```

### 5. main.cpp
```
#include "DLL_playlist.h"

address getNodeAt(List L, int posisi) {
    int idx = 1;
    address P = L.head;
    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }
    return P;
}

int main() {
    List L;
    createList(L);

    insertLast(L, {"Senja di Kota", "Nona Band", 210, 150, 4.2});
    insertLast(L, {"Langkahmu", "Delta", 185, 320, 4.8});
    insertLast(L, {"Hujan Minggu", "Arka", 240, 90, 3.95});

    cout << "\n=== List Awal ===\n";
    viewList(L);

    Song removed;
    deleteLast(L, removed);

    cout << "\n Setelah deleteLast \n";
    viewList(L);

    cout << "\n Update posisi ke-2 \n";
    updateAtPosition(L, 2);

    cout << "\n Setelah Update \n";
    viewList(L);

    address pos2 = getNodeAt(L, 2);

    insertBefore(L, pos2, {"Senandung", "Mira", 175, 120, 4.0});
    cout << "\n Setelah insertBefore posisi 2 \n";
    viewList(L);

    cout << "\n UpdateBefore posisi 2 \n";
    pos2 = getNodeAt(L, 2);
    updateBefore(L, pos2);

    cout << "\n Setelah updateBefore \n";
    viewList(L);

    cout << "\n deleteBefore posisi 3 \n";
    Song removed2;
    address pos3 = getNodeAt(L, 3);
    deleteBefore(L, pos3, removed2);

    cout << "\n Setelah deleteBefore \n";
    viewList(L);

    cout << "\n Searching PopularityScore 150–300 \n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
```

## Unguided 

### 1. SOAL.1
 ### buatlah program apapun bebas tetapi fungsi nya sama seperti tadi

 
### listbarang.cpp
```c++
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


```

### listbarang.h
```c++
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
```

### main.cpp
```c++
#include "listBarang.h"

int main() {
    List L;
    createList(L);

    address A, B, C, D, E;

    A = alokasi("Laptop", 10, 7500000);
    B = alokasi("Mouse", 50, 150000);
    C = alokasi("Keyboard", 30, 300000);
    D = alokasi("Monitor", 20, 2000000);
    E = alokasi("Printer", 5, 2500000);

    insertAwal(L, A);
    insertAkhir(L, B);
    insertSetelah(L, A, C);
    insertSetelah(L, C, D);
    insertAkhir(L, E);

    cout << "=== Data Barang ===\n";
    tampilList(L);
    cout << "Jumlah node: " << jumlahNode(L) << endl;

    cout << "\n--- Searching ---\n";
    cariNama(L, "Mouse");
    cariAlamat(L, C);
    cariRangeHarga(L, 100000, 1000000);

    cout << "\n--- Delete ---\n";
    deleteAwal(L);
    deleteAkhir(L);
    deleteSetelah(L, A);

    cout << "\n=== Data Setelah Delete ===\n";
    tampilList(L);

    return 0;
}


```
#### Output:
<img width="1238" height="878" alt="image" src="https://github.com/user-attachments/assets/fbb841fb-4db6-45c5-85c2-e6a3776371e5" />


1. Penjelasan listBarang.h

- File header ini berfungsi sebagai deklarasi struktur data dan prototipe fungsi
- Mendefinisikan struktur data Barang yang menyimpan atribut data berupa nama, stok, dan harga
- Mendefinisikan struktur Node sebagai elemen dasar singly linked list yang berisi data Barang dan pointer next
- Mendefinisikan struktur List untuk menyimpan alamat node pertama (first)

2. litsbarang.cpp
File ini berisi implementasi dari seluruh fungsi yang telah dideklarasikan 

Fungsi utamanya adalah:

- Inisialisasi dan validasi list:
Mengatur kondisi awal list agar kosong dan menyediakan pengecekan apakah list memiliki elemen atau tidak.

- Manajemen memori dinamis:
Mengalokasikan node baru menggunakan new dan menghapus node menggunakan delete untuk mencegah memory leak.

- Operasi penyisipan (Insert):
Menyediakan mekanisme penambahan node di awal, di akhir, dan setelah node tertentu dengan pengaturan pointer next.

- Operasi penghapusan (Delete):
Menghapus node dari awal, akhir, dan setelah node tertentu secara aman dengan memperhatikan kondisi list kosong atau hanya memiliki satu node

3. main.cpp
File ini berperan sebagai program utama (driver program) untuk menguji dan menjalankan fungsi-fungsi dari linked list.

fungsinya untuk:
- Membuat dan menginisialisasi objek list.
- Mengalokasikan beberapa node dengan data awal.
- Melakukan operasi penambahan node menggunakan berbagai metode (awal, akhir, dan setelah node tertentu).
- Menampilkan isi list dan jumlah node.
- Menguji operasi update data pada node tertentu.
- Melakukan berbagai metode pencarian data.
- Menguji operasi penghapusan node (awal, akhir, dan setelah node tertentu).
- Menampilkan kondisi akhir list dan menghapus seluruh elemen list.

#### Full code Screenshot:
### listbarang.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/cc6110af-fd04-4e5a-a835-f42ef9777e31" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/c5263b3c-8c62-4f90-8b97-375f303a44e1" />


### listbarang.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/b149a4b7-97ea-4f67-84d9-03db3023e4be" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/b3cc1b27-bd25-4e92-bd5b-0890160430ee" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5ab92ddd-a9d4-45dd-b190-59a8be6a6f74" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/32c0a7e4-8fea-4a55-9340-c2875756a2e7" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/b97b6de3-1a51-43fc-a440-3324691e52ab" />


### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/8af8eddd-f803-47b7-9033-532318a479e4" />



## Kesimpulan
Singly Linked List merupakan struktur data dinamis yang menyimpan elemen dalam bentuk node yang saling terhubung menggunakan pointer. Setiap node terdiri dari dua bagian utama, yaitu data dan penunjuk ke node berikutnya. Struktur ini memungkinkan operasi penambahan dan penghapusan data dilakukan secara fleksibel tanpa memerlukan ruang memori yang berurutan seperti pada array.

Melalui implementasi program, dapat disimpulkan bahwa Singly Linked List sangat efektif untuk pengelolaan data yang membutuhkan operasi dinamis seperti insert, delete, update, dan searching. Selain itu, pemisahan kode ke dalam file header (.h), source (.cpp), dan main program (main.cpp) membuat program lebih terstruktur, mudah dibaca, serta lebih mudah dalam pengembangan dan pemeliharaan di masa mendatang.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
