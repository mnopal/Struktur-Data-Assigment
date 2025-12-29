 <h1 align="center">Laporan Praktikum Modul Multi Linked List </h1>
<p align="center">MUHAMMAD NAUFAL</p>
 
## Dasar Teori
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau
suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang
sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar.
Manfaat penggunaan sub program antara lain adalah :
1. meningkatkan readibility, yaitu mempermudah pembacaan program
2. meningkatkan modularity, yaitu memecah sesuatu yang besar menjadi modul-modul atau
bagian-bagian yang lebih kecil sesuai dengan fungsinya, sehingga mempermudah
pengecekan, testing dan lokalisasi kesalahan.
3. meningkatkan reusability, yaitu suatu sub program dapat dipakai berulang kali dengan hanya
memanggil sub program tersebut tanpa menuliskan perintah-perintah yang semestinya
diulang-ulang.
Sub Program Rekursif adalah sub program yang memanggil dirinya sendiri selama kondisi pemanggilan
dipenuhi. Prinsip rekursif sangat berkaitan erat dengan bentuk induksi matematika. 




## Guided 

### 1. bst.h

```C++
#ifndef BST_H
#define BST_H

#define Nil NULL

// Struktur node BST
struct BST {
    int angka;
    BST *left;
    BST *right;
};

// Tipe data
typedef BST* node;
typedef BST* BinTree;

// Fungsi dasar
bool isEmpty(BinTree tree);
void createTree(BinTree &tree);

// Alokasi & dealokasi
node alokasi(int angkaInput);
void dealokasi(node nodeHapus);

// Operasi BST
void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angkaCari);

// Traversal
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

// Delete
bool deleteNode(BinTree &tree, int angka);

// Utility
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);

// Informasi tree
int size(BinTree tree);
int height(BinTree tree);

#endif
```

### 2. bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

### 3. Main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

## Unguided 

### SOAL 1
<img width="1098" height="1089" alt="image" src="https://github.com/user-attachments/assets/76a9d0a1-de25-4c87-9275-78debe775d1d" />

 
### bstree.cpp
```c++
#include "bstree.h"

// Alokasi node baru
address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert node ke BST
void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Jika sama, tidak dimasukkan (hindari duplikat)
}

// Mencari node
address findNode(infotype x, address root) {
    if (root == NULL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

// Traversal InOrder
void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

```

### bstree.h
```c++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

// Type infotype : integer
typedef int infotype;

// Type address : pointer to Node
typedef struct Node* address;

// Type Node
struct Node {
    infotype info;
    address left;
    address right;
};

// Function & Procedure
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

#endif

```

### main.cpp
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); // duplikat, tidak masuk
    insertNode(root, 7);

    InOrder(root);

    return 0;
}

```
#### Output:
<img width="1542" height="339" alt="image" src="https://github.com/user-attachments/assets/f92f5aaf-86b5-4689-9d55-ee6f004f4e16" />


### full kode screenshot:
### main.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5936aeae-995c-4440-b2a1-739abf47bb0f" />

### bstree.h:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/e654de79-88cd-4822-a4a6-3184980e77c3" />


### bstree.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/7642ea34-f708-44aa-a06d-faf4b51e1fb2" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/b08c50e2-f83c-4f1c-a382-b74149cb21f9" />

### SOAL 2
<img width="976" height="1171" alt="image" src="https://github.com/user-attachments/assets/4d7108ce-89c6-47be-9222-199ddb6fac7c" />

### bstree.h
``` c++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

// Deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

```

### bstree.cpp
``` c++
#include "bstree.h"

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left)
                 + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->info
             + hitungTotalInfo(root->left)
             + hitungTotalInfo(root->right);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    } else {
        int kiri = hitungKedalaman(root->left, start + 1);
        int kanan = hitungKedalaman(root->right, start + 1);
        return (kiri > kanan) ? kiri : kanan;
    }
}


address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

```

### main.cpp
``` c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}

```
#### output
<img width="1319" height="442" alt="image" src="https://github.com/user-attachments/assets/991a308c-8803-4920-aaa9-e30f9c9f9ea6" />

### full kode screenshot:

### bstree.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/918edd4b-1747-4be5-9607-dce635684510" />

### bstree.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/85b4f3fc-371f-40b2-b016-4c02350510b1" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/4ff6876e-b97c-4319-8f38-2b9d18e16386" />

### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/c482dac6-f306-415b-9e02-dd90e5985e94" />


### soal 3
<img width="740" height="475" alt="Screenshot 2025-12-29 160822" src="https://github.com/user-attachments/assets/be6b554c-9a4c-47e9-8f27-2f0a8f25ce07" />

### bstree.cpp
``` c++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// fungsi membuat node baru
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// pre-order: Root - Left - Right
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// post-order: Left - Right - Root
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    // membentuk tree sesuai gambar
    Node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(7);

    root->left->left = newNode(2);
    root->left->right = newNode(5);

    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);

    cout << "Pre-order  : ";
    preOrder(root);

    cout << "\nPost-order : ";
    postOrder(root);

    return 0;
}

```

#### output
<img width="1037" height="208" alt="image" src="https://github.com/user-attachments/assets/28c9f129-98ef-4446-9137-d4b3422c5e3b" />

### full kode screenshot:

### bstree.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/7ba5517f-fd5a-46d4-b0a1-c8dbd09a5a2a" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/95d77ac5-90d0-499a-8edf-ef34c33dd20f" />


## Kesimpulan
Binary Search Tree (BST) merupakan salah satu struktur data non-linear yang menyimpan data secara terurut berdasarkan aturan bahwa setiap node memiliki nilai lebih kecil di subpohon kiri dan nilai lebih besar di subpohon kanan. Implementasi BST menggunakan konsep Abstract Data Type (ADT) memungkinkan pemisahan antara definisi struktur data dan implementasi operasinya, sehingga program menjadi lebih terstruktur dan mudah dikembangkan.

Melalui penerapan fungsi rekursif, BST dapat melakukan berbagai operasi penting seperti penyisipan data, traversal InOrder, pencarian node, perhitungan jumlah node, penjumlahan seluruh nilai node, serta penentuan kedalaman maksimum pohon. Traversal InOrder pada BST menghasilkan keluaran data yang terurut menaik, sedangkan fungsi perhitungan kedalaman menunjukkan tinggi maksimum dari pohon biner yang terbentuk.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

