#include <iostream>
using namespace std;

// Fungsi untuk menukar tiga nilai menggunakan POINTER
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi untuk menukar tiga nilai menggunakan REFERENCE
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    // untuk pointer
    int a = 1, b = 2, c = 3;
    cout << "pointer" << "(nilai sebelum tukar): " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "pointer" << "(nilai setelah tukar): " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl << endl;


    //  untuk reference 
    int a2 = 1, b2 = 2, c2 = 3;
    cout << "reference" << "(nilai sebelum tukuar): " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    tukarReference(a2, b2, c2);

    cout << "reference" << "(nilai sesudah proses): " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    return 0;
}
