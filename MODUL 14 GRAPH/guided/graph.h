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
