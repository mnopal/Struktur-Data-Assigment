# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

Bahasa C++ adalah salah satu bahasa pemrograman tingkat tinggi yang sangat populer dan banyak digunakan di berbagai bidang. C++ juga adalah bahasa pemrograman berorientasi objek (Object-Oriented Programming / OOP) yang dikembangkan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai pengembangan dari bahasa C. Nama "C++" sendiri melambangkan peningkatan dari "C" (karena ++ adalah operator increment dalam C). Selain itu C++ adalah bahasa pemrograman tingkat tinggi yang mendukung paradigma berorientasi-objek, generik, dan procedural. Dibuat oleh Bjarne Stroustrup sebagai perluasan C, C++ menekankan performa, kontrol memori, dan fleksibilitas — sehingga dipakai luas pada sistem operasi, game, embedded, keuangan performa tinggi, compiler, dll.

## Guided 

### 1. HELLO WORD

```C++
#include <iostream> 
using namespace std;

int main() {
     // 1. testing basic
     cout << "Hello World!!";
}
}
```
Kode di atas digunakan untuk mencetak teks "Hello World!!" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. INPUT OUTPUT
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    const float pi = 3.14;

    cout << "masukan angka: ";
    cin >> n;

    cout << "angka dikeluarkan: " << n << endl;
    cout << "nilai konstanta pi: " << pi << endl;
    return 0;

}
```
memiliki variable constant pi dengan nilai 3.14 dan ber type data float, memungkinkan agar user bisa enginput nilai dari suatu n dan cout << berfungsi sebagai output dari variabel

### 3. OPERATOR C++
```C++
#include <iostream>

using namespace std;

int main() {
    int a;
    int b;

    cout << "Masukkan angka1: ";
    cin >> a;
    cout << "Masukkan angka2: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //operator logika 
    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;

    return 0;
}
```
Program tersebut untuk menunjukkan cara kerja operator aritmatika dan operator perbandingan dalam C++. Program meminta pengguna memasukkan dua bilangan, lalu menampilkan hasil operasi aritmatika seperti penjumlahan, pengurangan, perkalian, pembagian, dan modulus. Karena menggunakan tipe data int, hasil pembagian akan dibulatkan ke bilangan bulat. Setelah itu, program menampilkan hasil perbandingan dua bilangan dengan operator lebih besar, lebih kecil, sama dengan, maupun tidak sama dengan. Hasil perbandingan ditampilkan dalam bentuk 1 jika benar (true) dan 0 jika salah (false). Dengan demikian, program ini memberikan gambaran sederhana tentang penggunaan operator dasar dalam C++.



## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
