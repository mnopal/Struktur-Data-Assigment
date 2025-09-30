#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

    //Inputan
     cout << "masukkan angka 1: " << endl;
     cin >> a;
     cout << "masukkan angka 2: " << endl;
     cin >> b;

    //Operasi Dasar
    cout << "Hasil Penjumlahan = " << (a+b) << endl;
    cout << "Hasil Pengurangan = " << (a-b) << endl;
    cout << "Hasil Perkalian = " << (a*b) << endl;
    cout << "Hasil Pembagian = " << (a/b) << endl;

    return 0;
}