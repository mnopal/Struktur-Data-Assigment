#include "DLLPlaylist.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(const playlist &p) {
    return p.first == nullptr;
}

void Createplaylist(playlist &p) {
    p.first = nullptr;
    p.last = nullptr;
}

node* allocate(const lagu *l) {
    node *n = new node;
    n->info = *l;     // copy isi lagu
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}

void deallocate(node *Node) {
    delete Node;
}

void insertfirst(playlist &p, const lagu &l) {
    node *n = allocate(&l);

    if (isEmpty(p)) {
        p.first = p.last = n;
    } else {
        n->next = p.first;
        p.first->prev = n;
        p.first = n;
    }
}

void insertlast(playlist &p, const lagu &l) {
    node *n = allocate(&l);

    if (isEmpty(p)) {
        p.first = p.last = n;
    } else {
        p.last->next = n;
        n->prev = p.last;
        p.last = n;
    }
}

void deletefirst(playlist &p, lagu &l) {
    if (isEmpty(p)) return;

    node *n = p.first;
    l = n->info;

    if (p.first == p.last) {     // hanya satu elemen
        p.first = p.last = nullptr;
    } else {
        p.first = n->next;
        p.first->prev = nullptr;
    }
    deallocate(n);
}

void deletelast(playlist &p, lagu &l) {
    if (isEmpty(p)) return;

    node *n = p.last;
    l = n->info;

    if (p.first == p.last) {     // hanya satu elemen
        p.first = p.last = nullptr;
    } else {
        p.last = n->prev;
        p.last->next = nullptr;
    }
    deallocate(n);
}

void showforward(const playlist &p) {
    if (isEmpty(p)) {
        cout << "Playlist kosong.\n";
        return;
    }

    node *cur = p.first;
    cout << "=== Playlist (Forward) ===\n";
    while (cur) {
        cout << cur->info.judul 
             << " - " << cur->info.artist
             << " | Durasi: " << cur->info.durationSec << " detik"
             << " | Play: " << cur->info.playCount
             << " | Rating: " << cur->info.rating
             << endl;
        cur = cur->next;
    }
}

void showbackward(const playlist &p) {
    if (isEmpty(p)) {
        cout << "Playlist kosong.\n";
        return;
    }

    node *cur = p.last;
    cout << "=== Playlist (Backward) ===\n";
    while (cur) {
        cout << cur->info.judul 
             << " - " << cur->info.artist
             << " | Durasi: " << cur->info.durationSec << " detik"
             << " | Play: " << cur->info.playCount
             << " | Rating: " << cur->info.rating
             << endl;
        cur = cur->prev;
    }
}

float totaldurasi(const playlist &p) {
    float total = 0;
    node *cur = p.first;

    while (cur) {
        total += cur->info.durationSec;
        cur = cur->next;
    }

    return total;
}

void carilagu(const playlist &p, const string &judul) {
    node *cur = p.first;
    bool found = false;

    while (cur) {
        if (cur->info.judul == judul) {
            cout << "Ditemukan: " << cur->info.judul
                 << " - " << cur->info.artist
                 << " (" << cur->info.durationSec << " detik)\n";
            found = true;
        }
        cur = cur->next;
    }

    if (!found) {
        cout << "Lagu tidak ditemukan.\n";
    }
}
