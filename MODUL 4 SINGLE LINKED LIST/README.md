 <h1 align="center">Laporan Praktikum Modul Abstract data type </h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

Singly Linked List adalah struktur data dinamis yang terdiri dari serangkaian elemen data yang saling terhubung menggunakan pointer.

Struktur Dasar:

- Setiap elemen (Node) memiliki dua bagian: Data (info) dan Successor (next).

- Linked List ini hanya memiliki satu arah pointer (next) dan hanya mendukung pembacaan maju.

- Elemen pertama ditunjuk oleh first/head, dan elemen terakhir menunjuk ke Nil/NULL.

Operasi Primitif Utama
Operasi-operasi dasar (ADT) pada Singly Linked List meliputi:


- Manajemen Memori: Alokasi (new/malloc) dan Dealokasi (delete/free).

- Modifikasi (Insert): Menyisipkan elemen di awal (InsertFirst), akhir (InsertLast), atau setelah node tertentu (InsertAfter).

- Penghapusan (Delete): Menghapus elemen di awal (DeleteFirst), akhir (DeleteLast), atau setelah node tertentu (DeleteAfter).

Akses: Mencakup CreateList, isEmpty, dan printInfo (untuk menampilkan isi list).
## Guided 

### 1. list.h

```C++
#ifndef LIST_H
#define LIST_H
#define nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &list);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

#endif
```

### 2. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```

### 3. Main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    //lanjutan
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    
    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}

//note: jika ingin hapus list maka lepas dulu pointer previousnya agar bisa hapus node

```

## Unguided 

### 1. SOAL.1
<img width="681" height="1158" alt="Screenshot 2025-12-07 104024" src="https://github.com/user-attachments/assets/533f2a68-52ec-4436-a87a-66c128e24e47" />

 
### singlylinkedlist.cpp
```c++
#include "Singlylinkedlist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address p = new ElmList;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address p) {
    delete p;
}

void insertFirst(List &L, address p) {
    p->next = L.First;
    L.First = p;
}

void printInfo(List L) {
    address p = L.First;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
}

```

### singlylinkedlist.h
```c++
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

// PROTOTYPE
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address p);
void printInfo(List L);
void insertFirst(List &L, address p);

#endif

```

### main.cpp
```c++
#include "Singlylinkedlist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```
#### Output:
<img width="1750" height="148" alt="image" src="https://github.com/user-attachments/assets/f540055f-6be2-443a-b4a0-37624ae6c3ff" />

Program tersebut digunakan untuk mengimplementasikan struktur data Singly Linked List serta mempraktikkan operasi dasar pada list, yaitu inisialisasi list, alokasi node, penyisipan elemen di awal list (insertFirst), dan penelusuran elemen (printInfo). Program ini bertujuan untuk menunjukkan bagaimana node saling terhubung melalui pointer serta bagaimana perubahan struktur list terjadi setelah operasi penyisipan.


#### Full code Screenshot:
### singlylinkedlist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/1aa9b2a6-86be-4148-a003-a25f52f32558" />

### singlylinkedlist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/2d05b6d6-8b7f-4d3b-9e7b-c08ba9ff8afb" />

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/f5f567ef-d6a0-4637-9e36-25d798ada193" />





### 2. SOAL.2
<img width="1061" height="389" alt="image" src="https://github.com/user-attachments/assets/58f97491-569b-4821-8712-3e54f015af1a" />


### singlylinkedlist.h
```c++
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#define nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List {
    address first;
};

// prosedur and function
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

//lanjutan untuk nomor 2
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);


#endif
```
### singlylinkedlist.cpp
```c++
#include "singlylinkedlist.h"
#include <iostream>
using namespace std;

// prosedur and function
void CreateList(List &L) {
    L.first = nil;
}

//buat gerbong atau node baru
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = nil;
    return P;
}

// Hapus node 
void dealokasi(address &P) {
    delete P;
}

// digunakan untuk menampilkan output dari node atau gerbong
void printInfo(List L){
    address  P = L.first;
    if (P == nil) {
        cout << "Listnya kosong" << endl;
    } else {
        while (P != nil) {
            cout << P -> info << " ";
            P = P -> next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P){
    P -> next = L.first;
    L.first = P;
}

// lanjutan untuk no 2
void deleteFirst(List &L) {
    if (L.first != nil) {
        address P = L.first;
        L.first = P -> next;
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    if (L.first == nil) {
        return;
    }
    if (L.first->next == nil) {
        dealokasi(L.first);
        L.first = nil;
    } else {
        address P = L.first;
        address Prec = nil; 
        while (P->next != nil) {
            Prec = P;
            P = P->next;
        }
        
        Prec->next = nil; 
        dealokasi(P);     
    }

}
void deleteAfter(List &L, address Prec) {
    if (Prec != nil && Prec->next != nil) {
        address P = Prec->next;
        Prec->next = P->next;  
        dealokasi(P); 
    }
}
int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != nil) {
        count++;
        P = P -> next;
    }
    return count;
}
void deleteList(List &L) {
    address P = L.first;
    while (P != nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp); 
    }
    L.first = nil; 
}
```
main.cpp
``` c++
#include "Singlylinkedlist.h"

#include <iostream>
using namespace std;

int main () {
    List L;
    address P1, P2, P3, P4, P5 = nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);


    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    cout << "Soal 2 terkait delete" << endl;

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,P4);

    printInfo(L);
    cout << "Jumlah Node: "<< nbList(L) << endl;

    deleteList(L);
    cout << "List Berhasil Terhapus" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}

```

### OUTPUT
<img width="1290" height="303" alt="image" src="https://github.com/user-attachments/assets/55d9b94e-78c2-4124-a03e-9ef01615db75" />


Program nomor 2 merupakan pengembangan dari program sebelumnya dengan menambahkan fitur penghapusan node pada singly linked list. Program tetap menggunakan konsep ADT dengan tiga file: Singlylist.h berisi deklarasi fungsi deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList; Singlylist.cpp berisi implementasi fungsi-fungsi tersebut; dan main.cpp digunakan untuk menjalankan serta menguji program.

Pada pengujian, list awal 9 → 12 → 8 → 0 → 2 dimodifikasi dengan menghapus elemen pertama, terakhir, dan node tertentu sehingga tersisa 12 → 0. Selain itu, program juga menghitung jumlah node yang tersisa dan menghapus seluruh isi list.

### FULL CODE SCREENSHOT

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/f06d5960-3202-40b4-bafd-14e0ac692da1" />

### singlylinkedlist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/f0685b07-3ff8-430d-9258-235080aa5c80" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/8a67db2f-a379-4064-b6b1-e4393bebd346" />

### singlylinkedlist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/34829842-3b9e-4558-be61-07ced58540b0" />





## Kesimpulan
kesimpulan praktikum ini badalah memahami dan mengimplementasikan Singly Linked List (List Berantai Tunggal) menggunakan bahasa pemrograman C++ dengan pendekatan Abstract Data Type (ADT).

Konsep Dasar dan Struktur
Definisi: Singly Linked List adalah struktur data dinamis yang terdiri dari serangkaian elemen data (node) yang saling terhubung menggunakan pointer

Komponen Node: Setiap elemen (node) terdiri dari dua bagian utama:

- Data (info): Informasi utama yang disimpan.

- Successor (next): Pointer yang menyimpan alamat elemen berikutnya.

Karakteristik: List ini hanya memiliki satu arah pointer , sehingga hanya mendukung pembacaan maju. Elemen pertama diacu oleh pointer first/head , dan elemen terakhir akan menunjuk ke Nil/NULL.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
