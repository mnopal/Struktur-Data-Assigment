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