 <h1 align="center">Laporan Praktikum Modul Graph </h1>
<p align="center">MUHAMMAD NAUFAL</p>
 
## Dasar Teori
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh
sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda
dan Common Lab merupakan node (vertec). Jalan yang menghubungkan tempat Kost dan Common
Lab merupakan garis penghubung antara keduanya (edge).

## Guided 

### 1. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph; 
typedef struct Elmnode *adrNode;
typedef struct Elmedge *adrEdge;

struct Elmnode {
    infoGraph info;    //menyimpan data node (misal: char/int)
    int visited;       //penanda untuk traversal (0/1) penanda apakah node pernah dikunjungi)
    adrEdge firstEdge; //pointer pertama ke edge yg terhubung.
    adrNode Next;      //pointer ke node berikutnya dalam graph

};

struct Elmedge {
    adrNode node;    //pointer yg menunjuk ke lokasi node tujuan
    adrEdge next;    //pointer ke edge berikutnya 
} ;

struct Graph{
    adrNode first;    //poiinter ke node pertama dalam list graph

};

void CreateGraph (Graph &G);    // set first = NULL
adrNode AlokasiNode(infoGraph data);   //alokasin node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);   //alokasi edge baru 

void InsertNode(Graph &G, infoGraph data);   //menambahkan node
adrNode FindNode(Graph G, infoGraph data);   //mencari node
void ConnectNode(Graph &G, infoGraph info1,  infoGraph info2);   //menghubungkan node 
void disconnectNode( Graph &G, infoGraph info1, infoGraph info2);   //meemutuskan hubungan node
void DeleteNode(Graph &G, infoGraph X);   // menghapus node dan edge

void PrintinfoGraph(Graph G);   //menampilkan adjacency list
void ResetVisited(Graph &G);    //reset visited 
void PrintBFS(Graph G, infoGraph Startinfo);   //traversal BFS
void PrintDFS(Graph G, infoGraph startinfo);   //traversalDFS

#endif


```

### 2. graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.first = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new Elmnode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new Elmedge;
    edgeBaru->node = nodeTujuan;
    edgeBaru->next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.first == NULL) {
        G.first = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->next = edgeBantu->next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.first;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.first == nodeHapus) {
        //jika nodeHapus di awal
        G.first = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.first;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->node->visited == 0) {
                edgeBantu->node->visited = 1;
                Qyu.push(edgeBantu->node);
            }
            edgeBantu = edgeBantu->next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->node->visited == 0) {
                    Stak.push(edgeBantu->node);
                }
                edgeBantu = edgeBantu->next;
            }
        }
    }
    cout << endl;
}

```

### 3. Main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintinfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintinfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}

```

## Unguided 

### SOAL 1
<img width="958" height="857" alt="Screenshot 2025-12-30 155958" src="https://github.com/user-attachments/assets/29f542ca-dc21-4d05-a10d-ec2b3fdca2c3" />


### graph.cpp
```c++
#include "graph.h"

// Membuat graph kosong
void CreateGraph(Graph &G) {
    G.first = NULL;
}

// Alokasi node graph
adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

// Alokasi edge
adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

// Insert node ke graph
void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AlokasiNode(X);

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

// Cari node
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

// Hubungkan dua node (tidak berarah)
void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 → N2
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 → N1
        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

// Cetak graph
void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info;
            if (E->Next != NULL) {
                cout << " -> ";
            }
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}



```

### graph.h
```c++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;


struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};


struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};


struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif


```

### main.cpp
```c++
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    // Insert node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Ambil alamat node
    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    // Hubungan sesuai gambar
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    // Cetak graph
    PrintInfoGraph(G);

    return 0;
}



```
#### Output:
<img width="1218" height="304" alt="image" src="https://github.com/user-attachments/assets/d242d0b3-1dad-4413-bd6e-48a846f347a0" />



### full kode screenshot:
### main.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/e53970ea-6517-4d6b-b02a-89ae64ea39f9" />



### graph.h:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/02927d21-e103-4313-a47b-02e6ea011ba2" />




### graph.cpp:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/358e6363-2069-46f3-b039-7bee2d4b34d7" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/edfef1b9-8003-4251-9c2b-d0b01feb4dc0" />







### SOAL 2
<img width="923" height="401" alt="image" src="https://github.com/user-attachments/assets/e9745e4c-3824-4338-90a4-9a7b6b2a90c1" />




### graph.h
``` c++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N); // Prosedur baru

#endif

```

### graph.cpp
``` c++
#include "graph.h"
#include <iostream>
#include <stack>
using namespace std;

// Membuat graph kosong
void CreateGraph(Graph &G) {
    G.first = NULL;
}

// Alokasi node graph
adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

// Alokasi edge
adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

// Insert node ke graph
void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AlokasiNode(X);

    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

// Cari node
adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

// Hubungkan dua node (tidak berarah)
void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 → N2
        adrEdge E1 = AlokasiEdge(N2);
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 → N1
        adrEdge E2 = AlokasiEdge(N1);
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

// Cetak graph
void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info;
            if (E->Next != NULL) {
                cout << " -> ";
            }
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

// Prosedur DFS menggunakan rekursi (helper function)
void DFSRecursive(adrNode Current) {
    if (Current->visited == 1) return;
    
    cout << Current->info;
    Current->visited = 1;
    
    // Kunjungi semua tetangga
    adrEdge E = Current->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0) {
            cout << " -> ";
            DFSRecursive(E->Node);
        }
        E = E->Next;
    }
}

// Prosedur utama DFS (non-rekursif wrapper)
void PrintDFS(Graph G, adrNode StartNode) {
    if (StartNode == NULL) {
        cout << "Node awal tidak ditemukan!" << endl;
        return;
    }

    // Reset visited flag untuk semua node
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }

    cout << "Hasil Penelusuran DFS dari node " << StartNode->info << ": ";
    DFSRecursive(StartNode);
    cout << endl;
}

```

### main.cpp
``` c++
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    // Insert node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Ambil alamat node
    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    // Hubungan sesuai gambar
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    // Cetak struktur graph
    cout << "Struktur Graph:" << endl;
    PrintInfoGraph(G);
    cout << endl;

    // Test DFS dari node A
    PrintDFS(G, A);

    // Test DFS dari node B
    PrintDFS(G, B);

    // Test DFS dari node H
    PrintDFS(G, H);

    return 0;
}
```
#### output
<img width="1308" height="489" alt="image" src="https://github.com/user-attachments/assets/109a4f41-26cd-41cb-8326-7039d278e639" />


### full kode screenshot:

### graph.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5eda054c-20a6-40b6-9a13-69769e2679d5" />



### circularlist.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/3c7f820b-831c-405a-8a28-8cd4791d3013" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/75528eb7-e42a-4e11-8c8e-dabadb06b0f1" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/c58a6b35-6902-4035-93b7-08bab35d3cca" />







### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/aba651f4-37b5-411c-a94b-6ed5d20c8557" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/3b9177d9-d3ce-41d3-b054-7c1191e98f3a" />


### SOAL 3
<img width="671" height="76" alt="image" src="https://github.com/user-attachments/assets/92fa974b-9aa5-4ba7-9c8c-85e2920d63d4" />




### graph.h
``` c++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintBFS(Graph G, adrNode N);  

#endif
```

### graph.cpp
``` c++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;


void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AlokasiNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AlokasiEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AlokasiNode(X);
    P->Next = G.first;
    G.first = P;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E = AlokasiEdge(N2);
    E->Next = N1->firstEdge;
    N1->firstEdge = E;
}



void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode StartNode) {
    if (StartNode == NULL) return;

    ResetVisited(G);
    queue<adrNode> Q;

    cout << "=== HASIL TRAVERSAL BFS ===" << endl;
    cout << "BFS Traversal: ";

    StartNode->visited = 1;
    Q.push(StartNode);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}

```

### main.cpp
``` c++
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    PrintBFS(G, A);

    return 0;
}


```
#### output
<img width="1271" height="218" alt="image" src="https://github.com/user-attachments/assets/d168b755-38a3-493e-9906-0296a1e67517" /> 
Program ini digunakan untuk Breadth First Search (BFS) pada struktur data graph. Graph direpresentasikan menggunakan adjacency list, di mana setiap node memiliki daftar edge yang menunjukkan node-node tetangganya.

Proses BFS dilakukan dengan menggunakan struktur data queue. Penelusuran dimulai dari node awal, kemudian mengunjungi seluruh node tetangga terdekat terlebih dahulu sebelum melanjutkan ke level berikutnya. Untuk mencegah pengunjungan ulang, setiap node memiliki atribut visited yang akan ditandai ketika node tersebut telah dikunjungi.

Sebelum traversal dimulai, seluruh nilai visited direset agar penelusuran dapat dilakukan dengan benar. Selama proses BFS, node yang dikunjungi akan ditampilkan sesuai urutan penelusuran.


### full kode screenshot:

### graph.h
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/17228a8d-c107-456e-a3e0-e2351adee935" />


### graph.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/483dd22a-f633-446b-9e61-6b2d7f968caa" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/06343818-e4b5-4d48-b6bd-80b70e13dc0c" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/e40aabdf-2e35-45a8-bb7c-9f9c9fbdbfa6" />




### main.cpp
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/78b7cd20-ce7f-4880-b0a9-5e4d0904a3ab" />






## Kesimpulan
Pada praktikum ini saya memahami dan dapat mengimplementasikan struktur data graph menggunakan representasi adjacency list serta algoritma Breadth First Search (BFS) dan Depth First Search (DFS). BFS melakukan penelusuran graph secara melebar berdasarkan tingkat kedekatan node, sedangkan DFS melakukan penelusuran secara mendalam hingga mencapai node terdalam sebelum berpindah ke cabang lain. Melalui praktikum ini, pemahaman mengenai konsep graph dan perbedaan karakteristik kedua metode traversal tersebut dapat dipahami dengan baik.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

