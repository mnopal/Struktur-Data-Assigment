#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi
pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

