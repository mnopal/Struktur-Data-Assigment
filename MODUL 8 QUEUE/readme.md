 <h1 align="center">Laporan Praktikum Modul Queue </h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori
Queue (dibaca : kyu) merupakan struktur data yang dapat diumpamakan seperti sebuah antrean.
Misalkan antrean pada loket pembelian tiket Kereta Api. Orang yang akan mendapatkan pelayanan
yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia
akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list.
Dalam praktikum ini hanya akan dibahas pengimplementasian Queue dalam bentuk linked list.
Implementasi Queue dalam linked list sebenarnya tidak jauh berbeda dengan operasi list biasa,
malahan lebih sederhana. Karena sesuai dengan sifat FIFO dimana proses delete hanya dilakukan pada
bagian Head (depan list) dan proses insert selalu dilakukan pada bagian Tail (belakang list) atau
sebaliknya, tergantung dari persepsi masing-masing. Dalam penerapannya Queue dapat diterapkan
dalam Singly linked list dan Doubly linked list.




## Guided 

### 1. queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
```

### 2. queue.cpp
```C++
#include "queue.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    Paket P;
    cout << "Masukkan Kode Resi     : "; cin >> P.KodeResi;
    cout << "Masukkan Nama Pengirim : "; cin >> P.NamaPengirim;
    cout << "Masukkan Berat Barang  : "; cin >> P.BeratBarang;
    cout << "Masukkan Tujuan        : "; cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus paket dengan resi: " << Q.dataPaket[Q.Head].KodeResi << "\n";

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--;

    if (Q.Tail < 0) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n--- Daftar Paket dalam Antrian ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "  Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
        cout << "  Pengirim      : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "  Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "  Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
```

### 3. Main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Gojira Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Exit\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            enQueue(Q);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman: Rp. " 
                 << TotalBiayaPengiriman(Q) << endl;
            break;

        case 5:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}

```

## Unguided 

### SOAL DI JADIIN SATU
<img width="1004" height="1029" alt="image" src="https://github.com/user-attachments/assets/2514af54-6fbb-42df-8ccd-83128c74ef8f" />

 
### queue.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

// =========== FUNGSI UMUM (DIGUNAKAN OLEH SEMUA ALTERNATIF) ===========
void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.head << " - " << Q.tail << "\t: empty queue" << endl;
        return;
    }
    
    cout << Q.head << " - " << Q.tail << "\t: ";
    
    // Untuk alternatif 1 (geser) dan alternatif 2 (head maju)
    // Queue terisi dari head sampai tail
    if (Q.head <= Q.tail) {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    // Untuk alternatif 3 (circular) yang mungkin head > tail
    else {
        for (int i = Q.head; i < MAX; i++) {
            cout << Q.info[i] << " ";
        }
        for (int i = 0; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

// =========== SOAL 1: ALTERNATIF 1 (HEAD DIAM, TAIL BERGERAK - GESER ELEMEN) ===========
bool isFullQueue(Queue Q) {
    // Untuk alternatif 1, queue penuh ketika tail mencapai index terakhir
    return (Q.tail == MAX - 1);
}

void enqueue1(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[0] = x;
    } else {
        // Geser semua elemen ke kiri
        for (int i = Q.head; i <= Q.tail; i++) {
            Q.info[i - Q.head] = Q.info[i];
        }
        
        // Atur ulang head dan tail
        int jmlElemen = Q.tail - Q.head + 1;
        Q.tail = jmlElemen;
        Q.head = 0;
        
        // Tambah elemen baru di tail
        Q.info[Q.tail] = x;
    }
}

int dequeue1(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    
    int nilai = Q.info[Q.head];
    
    // Jika hanya 1 elemen
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    
    return nilai;
}

// =========== SOAL 2: ALTERNATIF 2 (HEAD BERGERAK, TAIL BERGERAK) ===========
void enqueue2(Queue &Q, infotype x) {
    // Untuk alternatif 2, queue penuh ketika tail mencapai MAX-1
    if (Q.tail == MAX - 1) {
        cout << "Queue penuh!" << endl;
        return;
    }
    
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    
    Q.info[Q.tail] = x;
}

int dequeue2(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    
    int nilai = Q.info[Q.head];
    
    // Jika hanya 1 elemen
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    
    return nilai;
}

// =========== SOAL 3: ALTERNATIF 3 (CIRCULAR QUEUE) ===========
bool isFullCircular(Queue Q) {
    // Cek apakah queue penuh (circular)
    // Queue penuh jika:
    // 1. tail berada tepat di belakang head (circular)
    // 2. Atau jika tail di MAX-1 dan head di 0
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue3(Queue &Q, infotype x) {
    if (isFullCircular(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    
    Q.info[Q.tail] = x;
}

int dequeue3(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    
    int nilai = Q.info[Q.head];
    
    // Jika hanya 1 elemen
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    
    return nilai;
}
```

### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

// Definisika ADT pada Queue array
typedef int infotype;
const int MAX = 5;
struct Queue {
    infotype info[MAX];
    int head, tail;
};

// deklaraasi fungsi atau procedur primitif
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void printInfo(Queue Q);

// soal 1
// Alternatif 1 (head diam, tail bergerak).
void enqueue1(Queue &Q, infotype x);
int dequeue1(Queue &Q);

// Soal 2: Alternatif 2 head dan tail bergerak
void enqueue2(Queue &Q, infotype x);
int dequeue2(Queue &Q);

// Soal 3: Alternatif 3 head dan tail berputar (Circular)
bool isFullCircular(Queue Q);
void enqueue3(Queue &Q, infotype x);
int dequeue3(Queue &Q);

#endif
```

### main.cpp
```c++
#include "queue.h"
#include <iostream>
using namespace std;

void runTest(int type) {
    Queue Q;
    CreateQueue(Q);

    cout << "--------------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "--------------------------------" << endl;

    // 1. Awal Kosong
    printInfo(Q);

    // 2. Enqueue 5
    if(type==1) enqueue1(Q, 5); else if(type==2) enqueue2(Q, 5); else enqueue3(Q, 5);
    printInfo(Q);

    // 3. Enqueue 2
    if(type==1) enqueue1(Q, 2); else if(type==2) enqueue2(Q, 2); else enqueue3(Q, 2);
    printInfo(Q);

    // 4. Enqueue 7
    if(type==1) enqueue1(Q, 7); else if(type==2) enqueue2(Q, 7); else enqueue3(Q, 7);
    printInfo(Q);

    // 5. Dequeue (Hapus 5)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 6. Dequeue (Hapus 2)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 7. Enqueue 4
    if(type==1) enqueue1(Q, 4); else if(type==2) enqueue2(Q, 4); else enqueue3(Q, 4);
    printInfo(Q);

    // 8. Dequeue (Hapus 7)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);

    // 9. Dequeue (Hapus 4 -> Kosong)
    if(type==1) dequeue1(Q); else if(type==2) dequeue2(Q); else dequeue3(Q);
    printInfo(Q);
}

int main() {
    cout << "Hello world!" << endl;

    cout << "\n=== SOAL 1 (ALTERNATIF 1: HEAD DIAM, TAIL BERGERAK) ===" << endl;
    runTest(1); // Ini yang akan PERSIS gambar 8-17

    cout << "\n=== SOAL 2 (ALTERNATIF 2: HEAD BERGERAK, TAIL BERGERAK) ===" << endl;
    runTest(2); // Head akan terus bertambah

    cout << "\n=== SOAL 3 (ALTERNATIF 3: HEAD DAN TAIL BERPUTAR) ===" << endl;
    runTest(3);

    return 0;
}


```
#### Output:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/1edbfe3b-a518-464e-bd97-8e11626cb23f" />

### full kode screenshot:
### main.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/433891e7-fe77-4400-9963-0feb788f201d" />

### queue.h:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/869e503f-cd5d-4969-bb70-96d9f2bf425d" />

### queue.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/204b6d1b-24ec-4e61-aa97-1f2b32c6da6e" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/4897aecf-8ce0-415e-b2cd-7919c367e277" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/f35358c9-96eb-4242-89e5-d74596a7c492" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/a3f01b6c-4687-472a-827a-eba33949630b" />


## Kesimpulan
berdasarkan tugas praktikum kali ini yaitu terdapat kesimpulan bahwa Queue adalah struktur data linear yang bekerja dengan prinsip FIFO (First In, First Out), yaitu elemen yang pertama masuk akan menjadi elemen pertama yang keluar. 
berikut beberapa pelajaran yg saya dapat di praktikum ini:
1. konsep dasar queue
   
Queue adalah struktur data FIFO (First In First Out) yang mirip dengan antrian nyata, di mana elemen yang pertama masuk akan pertama keluar.

2. Tiga Implementasi Array
- Head Diam, Tail Bergerak
Head tetap di indeks 0, tail bergerak dengan penggeseran elemen saat enqueue.

- Head & Tail Bergerak
Kedua pointer bergerak maju tanpa penggeseran, menyebabkan fragmentasi ruang.

- Circular Queue
Implementasi optimal menggunakan modulo untuk pointer berputar, memaksimalkan penggunaan array.

3. Kesimpulan Utama
- Circular Queue merupakan implementasi terbaik untuk penggunaan praktis
- Pemilihan metode bergantung pada kebutuhan: kesederhanaan vs efisiensi
- Queue array cocok untuk aplikasi dengan ukuran tetap, sedangkan linked list untuk ukuran dinamis
- Implementasi yang tepat memengaruhi performa sistem terutama pada aplikasi real-time


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

