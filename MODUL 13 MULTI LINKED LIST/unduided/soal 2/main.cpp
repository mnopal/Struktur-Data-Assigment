#include <iostream>
#include "multilist.h"
using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    // buat induk
    address A = alokasi(1);
    address B = alokasi(2);

    insertLast(L, A);
    insertLast(L, B);

    // buat anak untuk induk 1
    insertLastAnak(A->lanak, alokasiAnak(10));
    insertLastAnak(A->lanak, alokasiAnak(20));

    // buat anak untuk induk 2
    insertLastAnak(B->lanak, alokasiAnak(30));

    // tampilkan
    printInfo(L);

    cout << "Jumlah induk : " << nbList(L) << endl;
    cout << "Jumlah anak induk 1 : " << nbListAnak(A->lanak) << endl;

    return 0;
}
