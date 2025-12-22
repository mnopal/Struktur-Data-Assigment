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