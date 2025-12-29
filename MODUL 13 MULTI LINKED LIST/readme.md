 <h1 align="center">Laporan Praktikum Modul Multi Linked List </h1>
<p align="center">MUHAMMAD NAUFAL</p>
 
## Dasar Teori
Multi List merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama
lain. Tiap elemen dalam multi link list dapat membentuk list sendiri.Biasanya ada yang bersifat sebagai
list induk dan list anak .

Contoh Multi Linked list dapat dilihat pada gambar berikut:
<img width="1254" height="903" alt="image" src="https://github.com/user-attachments/assets/a644c8d6-737b-4a53-9b95-c20414c24e25" />
Jadi , dari implementasi di atas akan terdapat dua buah list, list pegawai dan list anak. Dimana untuk
list pegawai menunjuk satu buah list anak. Disini list induknya adalah list pegawai dan list anaknya
adalah list anak.


## Guided 

### 1. mll.h

```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

### 2. mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

```

### 3. Main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

## Unguided 

### SOAL 2
<img width="1649" height="92" alt="Screenshot 2025-12-29 190135" src="https://github.com/user-attachments/assets/59482aa5-2fe7-450f-bd77-5885c92e2405" />


 
### multilist.cpp
```c++
#include "multilist.h"
#include <iostream>
using namespace std;

/********* Pengecekan *********/
boolean ListEmpty(listinduk L) {
    return (L.first == Nil);
}

boolean ListEmptyAnak(listanak L) {
    return (L.first == Nil);
}

/********* Create List *********/
void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

/********* Alokasi *********/
address alokasi(infotypeinduk P) {
    address Q = new elemen_list_induk;
    Q->info = P;
    Q->next = Nil;
    Q->prev = Nil;
    CreateListAnak(Q->lanak);
    return Q;
}

address_anak alokasiAnak(infotypeanak P) {
    address_anak Q = new elemen_list_anak;
    Q->info = P;
    Q->next = Nil;
    Q->prev = Nil;
    return Q;
}

void dealokasi(address P) {
    delete P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

/********* Searching *********/
address findElm(listinduk L, infotypeinduk X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

address_anak findElm(listanak L, infotypeanak X) {
    address_anak P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    return P;
}

/********* Insert Induk *********/
void insertFirst(listinduk &L, address P) {
    if (ListEmpty(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (ListEmpty(L)) {
        insertFirst(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

/********* Insert Anak *********/
void insertFirstAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

/********* Print *********/
void printInfo(listinduk L) {
    address P = L.first;
    while (P != Nil) {
        cout << "Induk : " << P->info << " -> Anak : ";
        printInfoAnak(P->lanak);
        cout << endl;
        P = P->next;
    }
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
}

/********* Count *********/
int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

int nbListAnak(listanak L) {
    int n = 0;
    address_anak P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}

```

### multilist.h
```c++
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
typedef bool boolean;

/* tipe info */
typedef int infotypeanak;
typedef int infotypeinduk;

/* pointer address */
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* struktur elemen anak */
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

/* struktur list anak */
struct listanak {
    address_anak first;
    address_anak last;
};

/* struktur elemen induk */
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

/* struktur list induk */
struct listinduk {
    address first;
    address last;
};

/********* pengecekan *********/
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

/********* pembuatan list *********/
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/********* manajemen memori *********/
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);
void dealokasi(address P);
void dealokasiAnak(address_anak P);

/********* pencarian *********/
address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak L, infotypeanak X);

/********* penambahan elemen *********/
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);

void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);

/********* penghapusan elemen *********/
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);

void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);

/********* proses list *********/
void printInfo(listinduk L);
void printInfoAnak(listanak L);

int nbList(listinduk L);
int nbListAnak(listanak L);

#endif

```

### main.cpp
```c++
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


```
#### Output:
<img width="1109" height="211" alt="image" src="https://github.com/user-attachments/assets/f03b0308-19a0-4c70-b01e-3b0593a5e295" />



### full kode screenshot:
### main.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/1cf03432-4959-4e8f-aa89-3fc53e93dee3" />


### multilist.h:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/a1c2c63f-2999-45b0-933c-56eb6337efbc" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/2f8d204a-0941-4697-bda8-4fee582c3c84" />




### multilist.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/839746a3-9c4d-4acf-89c2-e3805b9c1f94" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/7be2025d-4989-4282-a293-426307eb368c" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/3c32a021-5078-4290-8a85-1f41425116da" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/626ec38b-efc8-43a2-bb6c-ef5e1892f742" />





### SOAL 3
<img width="680" height="467" alt="Screenshot 2025-12-29 194435" src="https://github.com/user-attachments/assets/39a39234-53c9-4d60-92ad-aa2c91a520c6" />
<img width="731" height="1023" alt="Screenshot 2025-12-29 194455" src="https://github.com/user-attachments/assets/c16418f8-b516-4cd9-a052-be319bd7f122" />
<img width="700" height="915" alt="Screenshot 2025-12-29 194540" src="https://github.com/user-attachments/assets/c7d872be-6b4f-41cd-a801-6f35f91f5606" />




### circularlist.h
``` c++
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

typedef struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
} infotype;

typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct List {
    address First;
} List;

// Procedure dan function untuk ADT circular list
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, infotype x);
void printInfo(List L);

#endif

```

### circularlist.cpp
``` c++
#include "circularlist.h"
#include <iomanip>

// Procedure CreateList: Membuat list kosong
void createList(List &L) {
    L.First = NULL;
}

// Function alokasi: Mengalokasikan elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

// Procedure dealokasi: Membebaskan memori elemen
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Procedure insertFirst: Menyisipkan elemen di awal list
void insertFirst(List &L, address P) {
    if (L.First == NULL) { // List kosong
        L.First = P;
        P->next = P; // Circular: menunjuk ke dirinya sendiri
    } else {
        // Cari elemen terakhir
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        
        P->next = L.First;
        L.First = P;
        last->next = P; // Update next dari elemen terakhir
    }
}

// Procedure insertAfter: Menyisipkan elemen setelah Prec
void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
        
        // Jika Prec adalah elemen terakhir, maka P menjadi elemen terakhir
        // Tidak perlu update karena sudah circular
    }
}

// Procedure insertLast: Menyisipkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == NULL) { // List kosong
        L.First = P;
        P->next = P;
    } else {
        // Cari elemen terakhir
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        
        last->next = P;
        P->next = L.First; // Circular: menunjuk ke elemen pertama
    }
}

// Procedure deleteFirst: Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        
        if (L.First->next == L.First) { // Hanya satu elemen
            L.First = NULL;
        } else {
            // Cari elemen terakhir
            address last = L.First;
            while (last->next != L.First) {
                last = last->next;
            }
            
            L.First = L.First->next;
            last->next = L.First; // Update next dari elemen terakhir
            P->next = NULL;
        }
    }
}

// Procedure deleteAfter: Menghapus elemen setelah Prec
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

// Procedure deleteLast: Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == L.First) { // Hanya satu elemen
            P = L.First;
            L.First = NULL;
        } else {
            // Cari elemen sebelum terakhir
            address prev = L.First;
            while (prev->next->next != L.First) {
                prev = prev->next;
            }
            
            P = prev->next;
            prev->next = L.First; // Update next dari elemen sebelum terakhir
            P->next = NULL;
        }
    }
}

// Function findElm: Mencari elemen berdasarkan NIM
address findElm(List L, infotype x) {
    if (L.First == NULL) {
        return NULL;
    }
    
    address P = L.First;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.First);
    
    return NULL;
}

// Procedure printInfo: Mencetak semua elemen dalam list
void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong" << endl;
        return;
    }
    
    address P = L.First;
    int count = 1;
    
    cout << "Isi List:" << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "Elemen ke-" << count << ":" << endl;
        cout << "Nama           : " << P->info.nama << endl;
        cout << "NIM            : " << P->info.nim << endl;
        cout << "Jenis Kelamin  : " << P->info.jenis_kelamin << endl;
        cout << "IPK            : " << fixed << setprecision(2) << P->info.ipk << endl;
        cout << "----------------------------------------" << endl;
        
        P = P->next;
        count++;
    } while (P != L.First);
    
    cout << "Total elemen: " << count-1 << endl;
    cout << "========================================" << endl;
}

```

### main.cpp
``` c++
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

```
#### output
<img width="1968" height="1304" alt="image" src="https://github.com/user-attachments/assets/7612bae1-bd0f-4d53-946e-e5fe6c3db266" />

### full kode screenshot:

### circularlist.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/15ea39cb-5cb8-4a46-b105-c5c303dc2415" />


### circularlist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/da147b8b-99af-4196-afe9-01319e458f44" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/e7aa2a36-c844-4977-920a-98f0da620d79" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/c20dc18d-e63d-4a40-bb8f-ff3fece0095d" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/534cbdb7-3fa4-422e-b560-22cd742d1b61" />




### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/aba651f4-37b5-411c-a94b-6ed5d20c8557" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/3b9177d9-d3ce-41d3-b054-7c1191e98f3a" />




## Kesimpulan
Berdasarkan studi kasus yang diberikan, dapat disimpulkan bahwa:

Definisi ADT: Abstract Data Type (ADT) Circular Linked List didefinisikan dengan tipe data infotype (mahasiswa), address (pointer), ElmList (elemen), dan List (struktur). ADT ini menyediakan operasi-operasi dasar untuk manipulasi list.

pada praktikum kali ini saya belajar materi multi linked list, list bersifat circular (melingkar) di mana elemen terakhir akan menunjuk ke elemen pertama, sehingga tidak ada elemen yang bernilai NULL pada pointer next kecuali list kosong.

Operasi yang Diimplementasikan:

- Pembuatan dan Alokasi: createList, alokasi, dealokasi.
- Penyisipan: insertFirst, insertAfter, insertLast.
- Penghapusan: deleteFirst, deleteAfter, deleteLast.
- Pencarian: findElm berdasarkan NIM.
- Traversal: printInfo untuk mencetak seluruh elemen.

Kompleksitas Waktu:

- Operasi insertFirst, insertLast, dan deleteLast memiliki kompleksitas O(n) karena harus menemukan elemen terakhir.
- Operasi insertAfter dan deleteAfter memiliki kompleksitas O(1) jika posisi pendahulu (Prec) diketahui.
- Operasi pencarian (findElm) memiliki kompleksitas O(n) karena harus melakukan traversal.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

