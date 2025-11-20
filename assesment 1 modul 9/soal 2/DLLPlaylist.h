#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>
using namespace std;

struct lagu {
    string judul;
    string artist;
    int durationSec;
    int playCount;
    float rating;
};

struct node {
    lagu info;
    node *next;
    node *prev;
};

struct playlist {
    node *first;
    node *last;
};

void Createplaylist (playlist &p);
node* allocate (const lagu *l);
void deallocate (node * Node);

void insertfirst (playlist &p, const lagu &l);
void insertlast (playlist &p, const lagu &l);
void deletefirst (playlist &p, lagu &l);
void deletelast (playlist &p, lagu &l);

void showforward (const playlist &p);
void showbackward ( const playlist &p);

float totaldurasi (const playlist &p);
void carilagu (const playlist &p, const string &judul);

#endif


