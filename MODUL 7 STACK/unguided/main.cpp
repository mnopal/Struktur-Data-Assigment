#include <iostream>
#include "stack.h"
using namespace std;

void soal1() {
    cout << "=== SOAL 1 ===" << endl;
    cout << "hello word" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout << endl;
}

void soal2() {
    cout << "=== SOAL 2 ===" << endl;
    cout << "hello word" << endl;
    Stack S2;
    createStack(S2);
    pushAscending(S2, 3);
    pushAscending(S2, 4);
    pushAscending(S2, 8);
    pushAscending(S2, 2);
    pushAscending(S2, 3);
    pushAscending(S2, 9);
    printInfo(S2);
    cout << "balik stack" << endl;
    balikStack(S2);
    printInfo(S2);
    cout << endl;
}

void soal3() {
    cout << "=== SOAL 3 ===" << endl;
     cout << "hello word" << endl;
    Stack S3;
    createStack(S3);
    
    // Clear input buffer sebelum membaca input
    cin.ignore();
    
    getInputStream(S3);
    printInfo(S3);
    cout << "balik stack" << endl;
    balikStack(S3);
    printInfo(S3);
    cout << endl;
}

int main() {
    int pilihan;
    
    do {
        cout << "=========================" << endl;
        cout << "PILIH SOAL STACK:" << endl;
        cout << "1. Soal 1 (Operasi dasar stack)" << endl;
        cout << "2. Soal 2 (Push ascending)" << endl;
        cout << "3. Soal 3 (Input stream)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                soal1();
                break;
            case 2:
                soal2();
                break;
            case 3:
                soal3();
                break;
            case 0:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
    } while(pilihan != 0);
    
    return 0;
}