#include "circularlist.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi createData: Membuat data baru (sudah diberikan)
address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    /* *
     * PR : mengalokasikan sebuah elemen list dengan info dengan info sesuai input
     * FS : address P menunjuk elemen dengan info sesuai input
     */
    infotype x;
    address P;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    P = alokasi(x);
    return P;
}

int main() {
    List L, A, B, L2;
    address P1 = NULL;
    address P2 = NULL;
    infotype x;
    createList(L);

    cout << "coba insert first, last, dan after" << endl;
    
    P1 = createData("Damu", "04", 'L', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'L', 3.45);
    insertLast(L, P1);
    
    P1 = createData("Bobi", "02", 'L', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'L', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'P', 3.75);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'P', 3.5);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'P', 3.3);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'P', 3.4);
    insertAfter(L, P1, P2);
    
    printInfo(L);
    
    // Contoh operasi delete (opsional untuk demonstrasi)
    cout << "\n\nSetelah deleteFirst:" << endl;
    deleteFirst(L, P1);
    dealokasi(P1);
    printInfo(L);
    
    cout << "\n\nMencari elemen dengan NIM '05':" << endl;
    x.nim = "05";
    P1 = findElm(L, x);
    if (P1 != NULL) {
        cout << "Ditemukan: " << P1->info.nama << endl;
    } else {
        cout << "Tidak ditemukan" << endl;
    }
    
    return 0;
}