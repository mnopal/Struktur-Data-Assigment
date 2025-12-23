#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);
    
    // Tambahkan data 
    kendaraan data1 = {"D001", "hitam", 90};
    kendaraan data2 = {"D002", "merah", 95};
    kendaraan data3 = {"D003", "biru", 98};
    kendaraan data4 = {"D004", "kuning", 90};
    
    insertLast(L, alokasi(data1));
    insertLast(L, alokasi(data2));
    insertLast(L, alokasi(data3));
    insertLast(L, alokasi(data4));
    
    // Tampilkan data awal
    cout << "Data Awal:\n";
    printListWithWarna(L);
    
    
    // Proses delete 
    string deleteNopol;
    cout << "\n---\n";
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> deleteNopol;
    
    if (deleteByNopol(L, deleteNopol)) {
        cout << "Data dengan nomor polisi " << deleteNopol << " berhasil dihapus.\n";
    } else {
        cout << "Data dengan nomor polisi " << deleteNopol << " tidak ditemukan.\n";
    }
    
    // data setelah delete
    cout << "\n---\n";
    printListWithWarna(L);
    
    return 0;
}