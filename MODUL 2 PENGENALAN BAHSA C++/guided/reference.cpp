#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp= x;
    x = y;
    y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;
    
    cout << "nilai a: " << a << endl;
    cout << "alamat a (&a): " << &a << endl;
    cout << "nilai ref (alias a) : " << ref << endl;
    cout << "alamat ref (&ref) : " << &ref << endl;

    // mengubah nilai a lewat reference 

    ref = 50;
    cout << "\nsetelah ref = 50;" << endl;
    cout << "nilai a:" << a << endl;
    cout << "nilai ref:" << ref << endl;
    
    tukar (a, b);
    cout << "after swapping, value of a = " << a << " end b = " << b << endl;
    return 0;
}