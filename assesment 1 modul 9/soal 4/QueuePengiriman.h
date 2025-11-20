#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; // kg
    string Tujuan;
};

const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi &Q);
bool isFull(QueueEkspedisi &Q);

void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, Paket P);
void deQueue(QueueEkspedisi &Q, Paket &P);

void viewQueue(QueueEkspedisi &Q);

// Bagian B
int TotalBiayaPengiriman(QueueEkspedisi &Q);

#endif
