#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp= *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;
    
    cout << "value of a: " << a << endl;
    cout << "addres of a: " << &a << endl;
    cout << "value stored in ptr (addres of a) : " << ptr << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;
    
    tukar (&a, &b);
    cout << "after swapping, value of a = " << a << " end b = " << b << endl;
    return 0;
}