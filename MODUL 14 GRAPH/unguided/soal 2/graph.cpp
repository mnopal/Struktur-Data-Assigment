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