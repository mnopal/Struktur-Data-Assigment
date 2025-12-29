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
