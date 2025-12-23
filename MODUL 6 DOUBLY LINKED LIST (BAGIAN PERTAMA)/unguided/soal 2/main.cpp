#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    int n = 4;
    for (int i = 0; i < n; i++) {
        kendaraan x;
        
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        if (cekNopol(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar!\n";
            i--; // Mengulang input untuk indeks yang sama
            continue;
        }
        
        cout << "masukkan warna: ";
        cin >> x.warna;
        
        cout << "masukkan tahun buat: ";
        cin >> x.thnBuat;

        address P = alokasi(x);
        insertLast(L, P);
        
        cout << endl;
    }

    // Menampilkan data dari belakang
    printInfo(L);

    // Pencarian data sesuai dengan gambar
    string searchNopol;
    cout << "\n---\n";
    cout << "Masukkan Nomor Polisi yang dicari    : ";
    cin >> searchNopol;
    
    address found = findElm(L, searchNopol);
    if (found != NULL) {
        cout << "====================================\n";
        cout << "Nomor Polisi    : " << found->info.nopol << endl;
        cout << "Warna           : " << found->info.warna << endl;
        cout << "Tahun           : " << found->info.thnBuat << endl;
        cout << "====================================\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }

    return 0;
}