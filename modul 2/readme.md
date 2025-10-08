 <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

Bahasa C++ adalah salah satu bahasa pemrograman tingkat tinggi yang sangat populer dan banyak digunakan di berbagai bidang. C++ juga adalah bahasa pemrograman berorientasi objek (Object-Oriented Programming / OOP) yang dikembangkan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai pengembangan dari bahasa C. Dalam modul ini kita belajar tentang array dan pointer. Adapun pengertian array dalam C++ adalah sekumpulan data dengan tipe yang sama yang disimpan berurutan dalam memori dan diakses melalui indeks. Array memudahkan penyimpanan serta pengolahan data dalam jumlah banyak, misalnya menampilkan, menjumlahkan, atau mencari nilai tertentu dengan bantuan perulangan.Dan pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, programmer dapat mengakses dan memanipulasi data secara langsung melalui alamat tersebut.

## Guided 

### 1. ARRAY

```C++
#include <iostream>
using namespace std;

int main() {
    //--- array 1 dimensi ---
    int arrID[5] = {10, 20, 30, 40, 50};
    cout << "array 1 dimensi;" <<endl;
    for (int i = 0; i < 5; i++) {
        cout << "arrID[" << i << "] = " << arrID[i] << endl; 
    }

    cout << endl;

    // --- array 2 dimensi (baris x kolom) ---
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    cout << "array 2 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D [i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // --- array multi dimensi (3D) ---
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "array 3 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j <<"][" << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }
    return 0;
}
```
Kode di atas menunjukkan perulangan array yg dimana dimensi 1 itu merintah agar data tersimpan berurutan, dan dimensi 2 membuat baris dan kolom dan dimensi 3 menyimpan data dalam bentuk lebih kompleks seperti kumpulan beberapa tabel

### 2. FUNCTION PROCEDUR
```C++
#include <iostream>
using namespace std;

void tulis(int x) {
    for(int i = 0; i < x; i++) {
        cout << "baris ke -: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Program ini berfungsi untuk menampilkan sejumlah baris teks sesuai jumlah yang dimasukkan oleh pengguna.Fungsi utamanya adalah melatih penggunaan fungsi (function) dan perulangan for dalam C++.

### 3. POINTER
```C++
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
```
Program ini bertujuan untuk memahami cara kerja pointer dan proses pertukaran nilai (swap) antar dua variabel menggunakan fungsi dan pointer di C++.
Melalui contoh ini, kamu bisa melihat bagaimana variabel, alamat memori, dan pointer saling berhubungan

### 4. REFERENCE
```C++
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
```
Program ini bertujuan untuk menjelaskan konsep referensi (reference) dalam C++ serta cara menukar nilai dua variabel menggunakan fungsi dengan parameter referensi.
Berbeda dengan pointer, reference tidak menyimpan alamat memori, tetapi menjadi nama lain dari variabel yang dirujuk



## Unguided 

### 1. SOAL.1
<img width="1750" height="144" alt="image" src="https://github.com/user-attachments/assets/008e026c-eb5f-4ad4-9b50-633ba153f013" />

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "Buat Matrix A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Buat Matrix B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nHasil Penjumlahan:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] - B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="1448" height="835" alt="image" src="https://github.com/user-attachments/assets/ccdc0e32-01c2-4dc1-a459-35e4113bcfe8" />


Program ini memperlihatkan cara melakukan operasi dasar pada matriks 3×3 di C++. menggunakan array dua dimensi untuk menyimpan data, Perulangan bersarang (for di dalam for) untuk mengakses elemen matriks, Menampilkan hasil penjumlahan, pengurangan, dan perkalian secara terpisah dengan tampilan rapi.


#### Full code Screenshot:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/bbc6b530-5162-4265-96c6-f3586b9100e0" />


### 2. SOAL.2
<img width="1644" height="350" alt="image" src="https://github.com/user-attachments/assets/67789612-9197-4ab8-b5e0-4fa0468c76a6" />

```c++
#include <iostream>
#include <string>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh",
                       "sebelas"};

    if (n < 12)
        return satuan[n];
    else if (n < 20)
        return satuan[n - 10] + " belas";
    else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa != 0)
            hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "error";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "error" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}
```

### OUTPUT
<img width="1190" height="184" alt="image" src="https://github.com/user-attachments/assets/1fac1a21-fa86-4241-ab18-6f2fc3e45b06" />

Program ini digunakan untuk mengubah angka menjadi tulisan dalam bahasa Indonesia untuk rentang 0 sampai 100. Fungsi angkaKeTulisan(int n) memanfaatkan array satuan[] berisi kata dari "nol" sampai "sebelas". tapi jika angka kurang dari 12, langsung dikembalikan sesuai array. Jika angka kurang dari 20, output berupa kata pada indeks n-10 ditambah kata "belas". Untuk angka puluhan (20–99), angka dibagi menjadi puluhan dan satuan. Kata "puluh" ditambahkan sesuai nilai puluh, dan jika ada sisa satuan, maka ditambahkan lagi. Jika angka sama dengan 100, hasilnya "seratus". Selain itu, program akan menampilkan "error".

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/39f66852-5d16-45c5-8dde-55a23c9d0161" />

### 3. SOAL.3
<img width="1174" height="461" alt="image" src="https://github.com/user-attachments/assets/377c21e1-541b-4445-bcda-35847e3ea5b7" />

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;

    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << " ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << "*";

        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
```

### OUTPUT
<img width="840" height="303" alt="image" src="https://github.com/user-attachments/assets/5305ac9d-cabb-4a6a-978c-5772d497fe58" />

Program di atas menunjukkan output berbentuk **segitiga simetris atau sama sisi** dengan memanfaatkan **perulangan `for`** sesuai input yang dimasukkan oleh pengguna. Nilai input `n` menentukan tinggi segitiga sekaligus jumlah baris yang akan dicetak. Setiap baris dibentuk melalui beberapa perulangan `for`, yaitu perulangan untuk mencetak spasi agar pola terlihat rata, perulangan untuk mencetak angka menurun dari `i` ke 1, pencetakan tanda bintang `*` sebagai titik tengah, serta perulangan untuk mencetak angka menaik dari 1 ke `i`. Kombinasi seluruh perulangan tersebut menghasilkan pola segitiga simetris dengan angka yang mengapit tanda bintang di tengah. Dengan demikian, program ini memperlihatkan bagaimana **struktur perulangan bersarang** dapat dimanfaatkan untuk membentuk pola yang teratur dan simetris.

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/77990b0d-084b-471c-896d-d51f77dd2e22" />


## Kesimpulan
Ringkasan dan interpretasi saya pada pembelajaran minggu ini adalah saya belajar tentang basic basic yang ada di bahasa c++ yang saya belum ketahui sebelumnya, dan saya juga masih tahap belajar juga untuk mengetahui bahsa c++ lebih dalam lagi dan macam macam seperti deklarasi variabel, tipe data, konstanta, for loop, do-while, struktur, dan juga di modul ini saya belajar syntax dari bahasa c++ juga.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

