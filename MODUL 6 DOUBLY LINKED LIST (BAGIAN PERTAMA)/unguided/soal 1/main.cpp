#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    int n = 4;
    for (int i = 0; i < n; i++) {
        kendaraan x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (cekNopol(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n\n";
            continue;   
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);
    return 0;
}
