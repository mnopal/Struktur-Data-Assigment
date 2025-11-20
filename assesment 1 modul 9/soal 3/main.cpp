#include <iostream>
#include "StackMahasiswa.h"

using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    // 2) Insert data mahasiswa (push 6 kali)
    Mahasiswa M1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa M2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa M3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa M4 = {"Wanderer7", "44444", 95.5, 85.5, 90.5};
    Mahasiswa M5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa M6 = {"Chasca", "66666", 99.9, 93.6, 87.3};

    Push(S, M1);
    Push(S, M2);
    Push(S, M3);
    Push(S, M4);
    Push(S, M5);
    Push(S, M6);

    // 3) Tampilkan stack
    cout << "\n-- STACK AWAL --\n";
    View(S);

    // 4) Pop 1x
    Mahasiswa removed;
    Pop(S, removed);
    cout << "\n-- SETELAH POP 1x (hapus: " << removed.Nama << ") --\n";
    View(S);

    // 5) Update posisi ke-3
    Mahasiswa newData = {"Heizou", "77777", 99.9, 88.8, 77.7};
    Update(S, 3, newData);

    cout << "\n-- SETELAH UPDATE POSISI 3 --\n";
    View(S);

    // 6) Searching nilai akhir range 85.5 - 95.5
    cout << "\n-- SEARCH NILAI AKHIR 85.5 - 95.5 --\n";
    SearchNilaiAkhir(S, 85.5f, 95.5f);

    // Bagian B – MaxNilaiAkhir()
    cout << "\n-- MAHASISWA DENGAN NILAI AKHIR MAKSIMUM --\n";
    MaxNilaiAkhir(S);

    return 0;
}
