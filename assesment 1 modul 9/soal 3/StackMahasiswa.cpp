#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }
    S.Top++;
    S.dataMahasiswa[S.Top] = M;
}

void Pop(StackMahasiswa &S, Mahasiswa &M) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    M = S.dataMahasiswa[S.Top];
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    // posisi ke-N  index = posisi - 1
    S.dataMahasiswa[posisi - 1] = M;
}

float HitungNilaiAkhir(const Mahasiswa &M) {
    return (0.2f * M.NilaiTugas) + (0.4f * M.NilaiUTS) + (0.4f * M.NilaiUAS);
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "TOP  bawah ke atas:\n";
    for (int i = S.Top; i >= 0; i--) {
        cout << "Posisi " << i + 1 << ": "
             << S.dataMahasiswa[i].Nama << " | "
             << S.dataMahasiswa[i].NIM << " | "
             << "Tgs:" << S.dataMahasiswa[i].NilaiTugas << " "
             << "UTS:" << S.dataMahasiswa[i].NilaiUTS << " "
             << "UAS:" << S.dataMahasiswa[i].NilaiUAS << " "
             << "NA:" << HitungNilaiAkhir(S.dataMahasiswa[i])
             << "\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max) {
    bool found = false;

    for (int i = S.Top; i >= 0; i--) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);

        if (NA >= min && NA <= max) {
            cout << "Ditemukan pada posisi " << i + 1 << ": "
                 << S.dataMahasiswa[i].Nama
                 << " | Nilai Akhir: " << NA << "\n";
            found = true;
        }
    }

    if (!found) cout << "Tidak ada data dalam rentang nilai tersebut.\n";
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    float maxVal = -9999;
    int pos = -1;

    for (int i = 0; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA > maxVal) {
            maxVal = NA;
            pos = i;
        }
    }

    cout << "Mahasiswa dengan nilai akhir tertinggi:\n";
    cout << "Posisi " << pos + 1 << ": "
         << S.dataMahasiswa[pos].Nama
         << " | Nilai Akhir: " << maxVal << "\n";
}
