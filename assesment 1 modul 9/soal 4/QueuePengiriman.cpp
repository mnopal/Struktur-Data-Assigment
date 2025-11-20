#include <iostream>
#include "QueuePengiriman.h"

using namespace std;

bool isEmpty(QueueEkspedisi &Q) {
    return Q.Head == -1 && Q.Tail == -1;
}

bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket P) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
        Q.dataPaket[0] = P;
    } else {
        Q.Tail++;
        Q.dataPaket[Q.Tail] = P;
    }
}

void deQueue(QueueEkspedisi &Q, Paket &P) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    P = Q.dataPaket[Q.Head];

    // Kalau hanya 1 data -> kosong
    if (Q.Head == Q.Tail) {
        Q.Head = -1;
        Q.Tail = -1;
    } else {
        // SHIFT KE KIRI (karena head tetap)
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        }
        Q.Tail--;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue masih kosong.\n";
        return;
    }

    cout << "\n=== Daftar Paket Dalam Queue ===\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "  Kode Resi     : " << Q.dataPaket[i].KodeResi << "\n";
        cout << "  Pengirim      : " << Q.dataPaket[i].NamaPengirim << "\n";
        cout << "  Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg\n";
        cout << "  Tujuan        : " << Q.dataPaket[i].Tujuan << "\n\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250; // biaya/kg
    }
    return total;
}
