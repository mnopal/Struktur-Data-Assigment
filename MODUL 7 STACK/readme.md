 <h1 align="center">Laporan Praktikum Modul Stack </h1>
<p align="center">MUHAMMAD NAUFAL</p>
 
## Dasar Teori
Stack adalah struktur data yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Struktur ini dapat diimplementasikan menggunakan dua representasi utama: representasi pointer yang bersifat dinamis dengan alokasi memori sesuai kebutuhan, dan representasi array yang bersifat statis dengan kapasitas tetap. Operasi dasar stack meliputi push untuk menambahkan elemen ke posisi teratas, pop untuk menghapus elemen dari posisi teratas, serta isEmpty untuk memeriksa apakah stack kosong, dengan kompleksitas waktu O(1) untuk operasi push dan pop. Stack memiliki berbagai aplikasi praktis seperti mekanisme undo/redo, manajemen pemanggilan fungsi, pengecekan sintaks, dan evaluasi ekspresi matematika. Kelebihan utamanya terletak pada kesederhanaan dan kecepatan operasi untuk pola akses LIFO, meskipun memiliki keterbatasan dalam hal akses yang hanya terbatas pada elemen teratas.

1. Pengertian Stack (Tumpukan)
Stack adalah struktur data linear yang mengikuti prinsip LIFO (Last In First Out), artinya elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Analoginya seperti tumpukan piring:

- Piring terakhir yang diletakkan (paling atas) adalah yang pertama diambil
- Piring pertama yang diletakkan (paling bawah) adalah yang terakhir diambil

2. Komponen Utama Stack
Top: Pointer yang menunjuk ke elemen teratas stack

Elemen-elemen: Data yang disimpan dalam stack



## Guided 

### 1. stack.h

```C++
#ifndef STACK
#define STACK
#include <iostream>
using namespace std;
#define Nil NULL

typedef struct node* address;
struct node {
    int dataAngka;
    address next;   
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int angka);

#endif
```

### 2. stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### 3. Main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    return 0;
}

```

## Unguided 

### 1. SOAL.1
 <img width="750" height="720" alt="image" src="https://github.com/user-attachments/assets/cc440a8c-7483-4ca1-9afc-cda73e38ca72" />


 
### stack.cpp
```c++
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1; // asumsi nilai invalid
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    // Pindahkan dari S ke temp hingga ditemukan posisi yang tepat
    while (S.top > 0 && S.info[S.top - 1] < x) {
        push(temp, pop(S));
    }

    // Masukkan x
    push(S, x);

    // Kembalikan dari temp ke S
    while (temp.top > 0) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan angka (akhiri dengan Enter): ";
    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0'); // konversi char ke int
        }
    }
}
```

### stack.h
```c++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX = 20;

typedef int infotype;
typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED
```

### main.cpp
```c++
#include <iostream>
#include "stack.h"
using namespace std;

void soal1() {
    cout << "=== SOAL 1 ===" << endl;
    cout << "hello word" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;
}

void soal2() {
    cout << "=== SOAL 2 ===" << endl;
    cout << "hello word" << endl;
    Stack S2;
    createStack(S2);
    pushAscending(S2, 3);
    pushAscending(S2, 4);
    pushAscending(S2, 8);
    pushAscending(S2, 2);
    pushAscending(S2, 3);
    pushAscending(S2, 9);
    printInfo(S2);
    cout << "balik stack" << endl;
    balikStack(S2);
    printInfo(S2);
    cout << endl;
}

void soal3() {
    cout << "=== SOAL 3 ===" << endl;
     cout << "hello word" << endl;
    Stack S3;
    createStack(S3);
    
    // Clear input buffer sebelum membaca input
    cin.ignore();
    
    getInputStream(S3);
    printInfo(S3);
    cout << "balik stack" << endl;
    balikStack(S3);
    printInfo(S3);
    cout << endl;
}

int main() {
    int pilihan;
    
    do {
        cout << "=========================" << endl;
        cout << "PILIH SOAL STACK:" << endl;
        cout << "1. Soal 1 (Operasi dasar stack)" << endl;
        cout << "2. Soal 2 (Push ascending)" << endl;
        cout << "3. Soal 3 (Input stream)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                soal1();
                break;
            case 2:
                soal2();
                break;
            case 3:
                soal3();
                break;
            case 0:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
    } while(pilihan != 0);
    
    return 0;
}


```
#### Output:
<img width="1729" height="1299" alt="image" src="https://github.com/user-attachments/assets/6386cb24-9cd2-4c8f-9524-5590b5688db8" />
<img width="1617" height="664" alt="image" src="https://github.com/user-attachments/assets/9162ddca-4605-4624-b364-9299ec77349e" />

### output soal 1:
<img width="369" height="251" alt="image" src="https://github.com/user-attachments/assets/b1955368-1386-45f6-a753-b58959882e77" />

### output soal 2:
<img width="388" height="255" alt="image" src="https://github.com/user-attachments/assets/64743fd4-47dc-4d2e-9832-c9bb7efb2e7c" />

### output soal 3:
<img width="801" height="283" alt="image" src="https://github.com/user-attachments/assets/65b1fde7-10d4-4ac7-b767-7acc611ff7b9" />



## Kesimpulan
Definisi: Struktur data LIFO (Last In First Out).

Karakteristik:
- Hanya akses elemen teratas (Top)
- Dua operasi utama: push (tambah) dan pop (hapus)
- Kompleksitas O(1) untuk operasi dasar

Implementasi:
- Pointer: Dinamis, kapasitas tak terbatas
- Array: Statis, kapasitas tetap
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
