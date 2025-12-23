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
```c++
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
 <img width="741" height="1118" alt="image" src="https://github.com/user-attachments/assets/7b9cf868-efb1-4100-9563-dd3bb2c81c1d" />

### doublylist.cpp
```c++
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
/* Mencari elemen berdasarkan nomor polisi */
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P; // Ditemukan
        }
        P = P->next;
    }
    return NULL; // Tidak ditemukan
}



```

### doublylist.h
```c++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

/* infotype */
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

/* address */
typedef struct ElmList *address;

/* Elemen List */
struct ElmList {
    kendaraan info;
    address next;
    address prev;
};

/* List */
struct List {
    address First;
    address Last;
};

/* Prototype ADT */
void CreateList(List &L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
bool cekNopol(List L, string nopol);

#endif

```

### main.cpp
```c++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    int n = 4;
    for (int i = 0; i < n; i++) {
        kendaraan x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (cekNopol(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n\n";
            continue;   
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);
    return 0;
}

```
#### Output:
<img width="1600" height="1000" alt="image" src="https://github.com/user-attachments/assets/be5c46ba-b760-4375-a66c-e2c9074c14a7" />


Program ini bertujuan untuk:
- Mengelola data kendaraan (nomor polisi, warna, tahun pembuatan) dalam struktur data linked list
- Menerapkan operasi dasar doubly linked list (insert, search, delete)
- Menyediakan antarmuka pengguna untuk input dan output data
- Mengimplementasikan validasi data (pengecekan duplikasi nomor polisi)

  
#### Full code Screenshot:
### doublylist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/8654078c-a958-47ee-a9cd-d689ccde3f0f" />

### listbarang.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/31583890-37c4-496b-8488-b3ca378a0b91" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/2922b855-a73a-4501-89c2-86f0036eaddc" />

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/9d06f2c3-c7e0-4cdf-a453-edf0aa3c3e51" />


### 2. SOAL 2
<img width="890" height="261" alt="image" src="https://github.com/user-attachments/assets/3f7c334d-ccb9-4303-b75f-c5bda10196b6" />

membuat fungsi baru.
fungsi findElm( L : List, x : infotype ) : address

### doublylist.cpp
``` c++
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

// Cek nomor polisi sudah ada atau belum 
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

// Mencari elemen berdasarkan nomor polisi 
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;  // Mengembalikan address jika ditemukan
        }
        P = P->next;
    }
    return NULL;  
}

// Insert di akhir list 
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

// Menampilkan isi list dari belakang 
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

// Menampilkan isi list dari depan 
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

//Menghapus elemen berdasarkan nomor polisi 
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

// Menghitung jumlah elemen dalam list 
int countElm(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

```

### doublylist.h
``` c++
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
void printForward(List L);
void deleteByNopol(List &L, string nopol);
int countElm(List L);

#endif

```

### main.cpp
``` c++
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    
    int n = 4;
    for (int i = 0; i < n; i++) {
        kendaraan x;
        
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        
        // Cek apakah nomor polisi sudah ada
        if (cekNopol(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar!\n";
            i--; 
            continue;
        }
        
        // Lanjut input data lainnya
        cout << "masukkan warna: ";
        cin >> x.warna;
        
        cout << "masukkan tahun buat: ";
        cin >> x.thnBuat;
        
        // Alokasi dan insert ke list
        address P = alokasi(x);
        insertLast(L, P);
        
        cout << endl; 
    }
    
    // Tampilkan semua data
    printInfo(L);
    
    // BAGIAN 2: PENCARIAN DATA
    cout << "\n---\n";
    string searchNopol;
    cout << "Masukkan Nomor Polisi yang dicari    : ";
    cin >> searchNopol;
    
    address found = findElm(L, searchNopol);
    if (found != NULL) {
        cout << "====================================\n";
        cout << "Nomor Polisi    : " << found->info.nopol << endl;
        cout << "warna           : " << found->info.warna << endl;  // "Marna" sesuai gambar
        cout << "Tahun           : " << found->info.thnBuat << endl;
        cout << "====================================\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
    
    return 0;
}
```
### Output:
<img width="1600" height="1000" alt="image" src="https://github.com/user-attachments/assets/febe1ab0-18a1-4b38-8b31-d661d57e4f51" />

Untuk bagian kedua soal, tugasnya serupa dengan bagian pertama, namun fokus pada pencarian elemen dengan nomor polisi D001. Di sini, Anda harus membuat fungsi baru bernama findElm yang berfungsi untuk mencari data tertentu pada suatu node dalam list. Fungsi ini akan menerima input (misalnya nomor polisi) dan mengembalikan alamat node jika data ditemukan, atau NULL jika tidak.

Setelah fungsi dibuat, nantinya output program akan menampilkan hasil pencarian sesuai kondisi:

Jika nomor polisi yang dicari ditemukan, program akan menampilkan data kendaraan yang sesuai.

Jika tidak ditemukan, program akan menampilkan pesan bahwa nomor polisi tersebut tidak ada dalam list.

#### Full code Screenshot:
### doublylist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/d705c658-aa15-4774-b3f8-6cf7722e7aeb" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/e18cd981-f3e4-4911-beaf-579759d2cc1d" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/0ee6804c-8ff8-4ea8-a866-1f77f903acee" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/3b2d6d74-d751-4fa4-b611-5d5b890aafae" />

### doublylist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5bdfc975-5ae3-4081-8920-cba7128e884a" />

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/8f406542-18b5-4bed-8d4b-1851c7c50371" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/14439b3c-35b2-4902-84a5-174794772bfe" />


### 3. SOAL 3
<img width="778" height="443" alt="image" src="https://github.com/user-attachments/assets/14358df9-a62c-4f21-89f9-b035a628a044" />

### doblylist.cpp
```c++
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
```

### doublylist.h
```c++
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
```

### main.cpp
```c++
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // Tambahkan data 
    kendaraan data1 = {"D001", "hitam", 90};
    kendaraan data2 = {"D002", "merah", 95};
    kendaraan data3 = {"D003", "biru", 98};
    kendaraan data4 = {"D004", "kuning", 90};
    
    insertLast(L, alokasi(data1));
    insertLast(L, alokasi(data2));
    insertLast(L, alokasi(data3));
    insertLast(L, alokasi(data4));
    
    // Tampilkan data awal
    cout << "Data Awal:\n";
    printListWithWarna(L);
    
    
    // Proses delete 
    string deleteNopol;
    cout << "\n---\n";
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> deleteNopol;
    
    if (deleteByNopol(L, deleteNopol)) {
        cout << "Data dengan nomor polisi " << deleteNopol << " berhasil dihapus.\n";
    } else {
        cout << "Data dengan nomor polisi " << deleteNopol << " tidak ditemukan.\n";
    }
    
    // data setelah delete
    cout << "\n---\n";
    printListWithWarna(L);
    
    return 0;
}
```

### Output :
<img width="1600" height="1000" alt="image" src="https://github.com/user-attachments/assets/4b32dbb8-c0a4-4d7c-9d6e-b8575426a52c" />

program tersebut masih melanjutkan kode dari bagian 1 dan 2. Setelah operasi Insert dan Searching berhasil diimplementasikan, sekarang kita akan menambahkan operasi Delete.

Kita perlu membuat tiga prosedur baru untuk penghapusan:

- deleteFirst – untuk menghapus node pertama
- deleteLast – untuk menghapus node terakhir
- deleteAfter – untuk menghapus node setelah node tertentu

Tujuan dari implementasi ini adalah agar pengguna dapat memasukkan node mana yang ingin dihapus. Program kemudian akan menentukan jenis penghapusan mana yang sesuai berdasarkan posisi node dalam list:

- Jika node berada di awal → gunakan deleteFirst
- Jika node berada di akhir → gunakan deleteLast
- Jika node berada di tengah → gunakan deleteAfter

#### Full code Screenshot:
### doublylist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/31a53def-051a-4a31-8e35-1c7200ac6b50" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/6312305a-4a19-41b0-889f-ebd66313b3f6" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/09c6018a-6536-4dee-95da-960ec30c8fb3" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/b642a62a-1660-483f-b829-e98e10ee246c" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/44857131-a580-4e44-b58a-e275119ffb3f" />

### doublylist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/18e0a7cd-0ed0-4503-bc1b-147b5802c8c9" />

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5af3fce0-575d-4ff3-aade-05fdc64ae370" />





## Kesimpulan
Berdasarkan hasil praktikum dan pembelajaran yang dilakukan, dapat diinterpretasikan bahwa Doubly Linked List (DLL) merupakan struktur data yang sangat optimal untuk menangani data yang bersifat dinamis dan memerlukan fleksibilitas tinggi dalam manipulasi.

Setiap node dalam DLL memiliki dua pointer: next (menunjuk ke node berikutnya) dan prev (menunjuk ke node sebelumnya). Desain ini memungkinkan:

- Penelusuran dua arah (traversal forward dan backward), sehingga pencarian data dapat dilakukan lebih efisien        dibanding Single Linked List (SLL).

- Operasi penghapusan dan penyisipan di posisi mana pun dalam list dapat dilakukan tanpa harus melakukan traversal    ulang dari awal, khususnya jika kita telah memiliki referensi ke node yang bersangkutan.

- Tidak perlu realokasi atau penggeseran massal elemen seperti pada array, sehingga lebih hemat waktu untuk operasi   yang sering mengubah struktur data.

Dalam konteks praktikum, implementasi DLL dengan operasi dasar seperti create, insert, search, dan delete (first, last, after) memberikan pemahaman nyata tentang bagaimana struktur ini mendukung manajemen data yang dinamis, responsif, dan efisien — cocok untuk aplikasi seperti manajemen riwayat, antrian prioritas dua arah, atau sistem navigasi data yang memerlukan akses maju dan mundur.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
