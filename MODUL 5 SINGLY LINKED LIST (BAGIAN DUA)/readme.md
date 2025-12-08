 <h1 align="center">Laporan Praktikum Modul Singly Linked List (bagian dua) </h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

Materi ini adalah lanjutan operasi dan implementasi dari struktur data Singly Linked List.

1.Konsep Dasar Linked List
Linked List adalah struktur data yang direpresentasikan secara fisik menggunakan pointer.

- Definisi List Kosong: List dianggap kosong jika elemen first (awal) menunjuk ke Nil (NULL).

- Elemen List: Setiap elemen diacu oleh address (pointer). Setiap elemen (struct elmlist) terdiri dari dua bagian:

- infotype info: Menyimpan data (tipe integer).




- next: Merupakan pointer ke elemen selanjutnya (address).


- Akses Elemen: Setiap elemen yang beralamat P dapat diacu menggunakan P->info atau P->next.

2.Operasi Dasar (ADT) pada Linked List
Operasi-operasi dasar ini (disebut Abstract Data Type/ADT) pada bahasa pemrograman C tersimpan dalam file *.c dan *.h. Modul ini mencantumkan prototype (deklarasi fungsi) untuk operasi-operasi tersebut.


## Guided 

### 1. listBuah.h

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define NIL NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;

typedef struct node *address;

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodebaru);
void insertAfter(linkedlist &list, address nodebaru, address prev);
void insertLast(linkedlist &list, address nodebaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodeprev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```

### 2. listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == NULL){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = NULL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = NULL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = NULL;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != NULL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == NULL){
            List.first->next = NULL;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != NULL){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NULL; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NULL && nodePrev->next != NULL) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = NULL;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NULL) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != NULL) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != NULL){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = NULL; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NULL) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != NULL) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 3. Main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    dataBuah dtbuah;

nodeA = alokasi("jeruk", 100, 3000);
nodeB = alokasi("apel", 75, 4000);
nodeC = alokasi("pir", 87, 5000);
nodeD = alokasi("semangka", 43, 11500);
nodeE = alokasi("durian", 15, 31450);

insertFirst(List, nodeA);
insertLast(List, nodeB);
insertAfter(List, nodeC, nodeA);
insertAfter(List, nodeD, nodeC);
insertLast(List, nodeE);

cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" <<endl;
printList(List);
cout << "jumlah node : " << nbList(List) << endl;
cout << endl;

updateFirst(List);
updateLast(List);
updateAfter(List, nodeD);

cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
printList(List);
cout << "jumlah node : " <<nbList(List) << endl;
cout << endl;

FindNodeByData(List, "kalpa");
FindNodeByAddress(List, nodeC);
FindNodeByRange(List, 50, 1000);

delFirst(List);
delLast(List);
delAfter(List, nodeD, nodeE);


cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
printList(List);
cout << "jumlah node ; " << nbList(List) << endl;
cout << endl;

deleteList(List);
cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
printList(List);
cout << "jumlah Node: " <<nbList(List) << endl;
return 0;
}

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
