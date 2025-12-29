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
