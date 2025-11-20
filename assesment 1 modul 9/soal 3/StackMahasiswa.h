#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);

void createStack(StackMahasiswa &S);

void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S, Mahasiswa &M);
void Update(StackMahasiswa &S, int posisi, Mahasiswa M);

void View(StackMahasiswa &S);

float HitungNilaiAkhir(const Mahasiswa &M);
void SearchNilaiAkhir(StackMahasiswa &S, float min, float max);

void MaxNilaiAkhir(StackMahasiswa &S);

#endif
