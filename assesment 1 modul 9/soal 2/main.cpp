#include <iostream>
#include "DLLPlaylist.h"

using namespace std;

int main() {
    playlist P;
    Createplaylist(P);

    //  1. Insert 3 lagu sesuai soal
    lagu L1 = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    lagu L2 = {"Langkahmu", "Delta", 185, 320, 4.8};
    lagu L3 = {"Hujan Minggu", "Arka", 240, 90, 3.9};

    insertlast(P, L1);
    insertlast(P, L2);
    insertlast(P, L3);

    cout << "\n=== LIST AWAL ===\n";
    showforward(P);

    // 2. deleteLast 1x
    lagu removed;
    deletelast(P, removed);

    cout << "\n=== SETELAH deleteLast (hapus: " << removed.judul << ") ===\n";
    showforward(P);

    // 3. update posisi ke-2 secara manual (karena tidak ada fungsi update)
    lagu newData = {"Pelita", "Luna", 200, 260, 4.5};

    node *cur = P.first;
    int pos = 1;
    while (cur != nullptr && pos < 2) {
        cur = cur->next;
        pos++;
    }
    if (cur != nullptr) {
        cur->info = newData;
    }

    cout << "\n=== SETELAH UPDATE POSISI 2 ===\n";
    showforward(P);

    // 4. Tampilkan backward
    cout << "\n=== LIST (BACKWARD) ===\n";
    showbackward(P);

    // 5. Total durasi
    cout << "\nTotal durasi playlist: " 
         << totaldurasi(P) << " detik\n";

    //  6. Pencarian lagu
    cout << "\nCari lagu 'Pelita':\n";
    carilagu(P, "Pelita");

    return 0;
}
