#include <iostream>
#include "QueuePengiriman.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            
            Paket P;
            cout << "\nKode Resi      : ";
            getline(cin, P.KodeResi);
            cout << "Nama Pengirim  : ";
            getline(cin, P.NamaPengirim);
            cout << "Berat Barang   : ";
            cin >> P.BeratBarang;
            cin.ignore();
            cout << "Tujuan         : ";
            getline(cin, P.Tujuan);

            enQueue(Q, P);

        } else if (pilihan == 2) {

            Paket removed;
            deQueue(Q, removed);

        } else if (pilihan == 3) {

            viewQueue(Q);

        } else if (pilihan == 4) {

            int total = TotalBiayaPengiriman(Q);
            cout << "Total Biaya Pengiriman: Rp " << total << "\n";

        }

    } while (pilihan != 0);

    return 0;
}
