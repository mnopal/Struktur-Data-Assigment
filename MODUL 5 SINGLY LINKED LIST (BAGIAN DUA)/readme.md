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
