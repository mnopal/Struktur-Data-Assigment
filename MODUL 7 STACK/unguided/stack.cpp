#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < MAX) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1; // asumsi nilai invalid
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    // Pindahkan dari S ke temp hingga ditemukan posisi yang tepat
    while (S.top > 0 && S.info[S.top - 1] < x) {
        push(temp, pop(S));
    }

    // Masukkan x
    push(S, x);

    // Kembalikan dari temp ke S
    while (temp.top > 0) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan angka (akhiri dengan Enter): ";
    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0'); // konversi char ke int
        }
    }
}