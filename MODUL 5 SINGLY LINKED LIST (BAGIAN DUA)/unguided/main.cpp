#include "listBarang.h"

int main() {
    List L;
    createList(L);

    address A, B, C, D, E;

    A = alokasi("Laptop", 10, 7500000);
    B = alokasi("Mouse", 50, 150000);
    C = alokasi("Keyboard", 30, 300000);
    D = alokasi("Monitor", 20, 2000000);
    E = alokasi("Printer", 5, 2500000);

    insertAwal(L, A);
    insertAkhir(L, B);
    insertSetelah(L, A, C);
    insertSetelah(L, C, D);
    insertAkhir(L, E);

    cout << "=== Data Barang ===\n";
    tampilList(L);
    cout << "Jumlah node: " << jumlahNode(L) << endl;

    cout << "\n--- Searching ---\n";
    cariNama(L, "Mouse");
    cariAlamat(L, C);
    cariRangeHarga(L, 100000, 1000000);

    cout << "\n--- Delete ---\n";
    deleteAwal(L);
    deleteAkhir(L);
    deleteSetelah(L, A);

    cout << "\n=== Data Setelah Delete ===\n";
    tampilList(L);

    return 0;
}
