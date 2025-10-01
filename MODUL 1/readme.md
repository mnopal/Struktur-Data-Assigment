 <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
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

### 4. PERCABANGAN
```C++
#include <iostream>
using namespace std;

int main() {
     int angka1 = 10;
     int angka2 = 20;
     if (angka1 > angka2) {
          cout << "Angka1 lebih besar dari angka2" << endl;
     } else if (angka1 < angka2) {
          cout << "Angka1 lebih kecil dari angka2" << endl;
     } else {
          cout << "Angka1 sama dengan angka2" << endl;
     }
}
```
Program di atas menunjukkan penggunaan percabangan if-else. Dua variabel angka1 = 10 dan angka2 = 20 dibandingkan. Jika angka1 lebih besar dari angka2, maka ditampilkan pesan sesuai kondisi. Jika lebih kecil, tampil pesan "Angka1 lebih kecil dari angka2". Jika nilainya sama, tampil pesan "Angka1 sama dengan angka2"

### 5. PERULANGAN FOR
```C++
#include <iostream>

using namespace std;

int main() {
    int i;
    int j;

    for (int i = 0; i <= 10; i++) {
        cout << i << "-" ;
    }
    cout << endl;

    for (int j = 20; j >= 10; j--) {
        cout << j << "-" ;
    }

    return 0;
}
```
Program tersebut menerapkan struktur perulangan for dalam C++. Perulangan pertama for (int i = 0; i <= 10; i++) digunakan untuk menampilkan deret bilangan dari 0 sampai dengan 10 secara berurutan naik, dengan setiap angka dipisahkan oleh tanda hubung (-). Setelah itu, perintah cout << endl; digunakan untuk membuat baris baru. perulangan kedua for (int j = 20; j >= 10; j--) menampilkan deret bilangan dari 20 hingga 10 secara berurutan turun, juga dengan pemisah tanda hubung. maka, program ini menunjukkan cara perulangan for dengan sempurna 

### 6. WHILE DO
```C++
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int j = 20;

    while (i <= 10) {
        cout << i << "-";
        i++;
    }

    cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j <=10);

    return 0;
}
```
Program di atas menunjukkan perulangan while dan do-while. Perulangan while mencetak angka dari 0 sampai 10 dengan tanda hubung. Sedangkan do-while mencetak angka 20 sekali saja, karena meskipun kondisi j <= 10 salah, blok do tetap dijalankan minimal satu kali

### 7. STRUKTUR
```C++
#include <iostream>
#include <string>
using namespace std;
struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    int jumlah;

    cout << "masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }
    
    cout << "\n === Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1 
             << "| Nama: |" << mhs[i].nama
             << "| Umur: |" << mhs[i].umur << endl;
    }
    return 0;
}
```
Program tersebut merupakan struktur data struct di C++ dengan contoh data mahasiswa. Pertama, didefinisikan sebuah struct Mahasiswa yang memiliki dua atribut, yaitu nama ber type data string dan umur ber type data int. Pada fungsi main, pengguna diminta memasukkan jumlah mahasiswa yang ingin dicatat. Setelah itu, dibuat array mhs[jumlah] untuk menampung data mahasiswa sesuai jumlah yang dimasukkan.

## Unguided 

### 1. SOAL.1
<img width="1722" height="166" alt="image" src="https://github.com/user-attachments/assets/040c4439-cecb-4bf5-8abc-751af905e878" />

```C++
#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

     cout << "masukkan angka 1: " << endl;
     cin >> a;
     cout << "masukkan angka 2: " << endl;
     cin >> b;

    cout << "Hasil Penjumlahan = " << (a+b) << endl;
    cout << "Hasil Pengurangan = " << (a-b) << endl;
    cout << "Hasil Perkalian = " << (a*b) << endl;
    cout << "Hasil Pembagian = " << (a/b) << endl;

    return 0;
}
```
#### Output:
<img width="1119" height="383" alt="image" src="https://github.com/user-attachments/assets/7721cadd-19dd-4f10-9c9f-31937c54fcdd" />

Program ini digunakan untuk menghitung **operasi aritmatika dasar** pada dua bilangan. Pengguna diminta memasukkan dua angka bertipe `float`, kemudian program menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari kedua angka tersebut. Karena menggunakan tipe data `float`, hasil yang ditampilkan dapat berupa bilangan desimal. Program ini menunjukkan penerapan sederhana operator aritmatika pada input dari pengguna.


#### Full code Screenshot:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/57d5823e-ffd1-4990-bcb8-cedb95660deb" />

### 1. SOAL.2
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

### 1. SOAL.3
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
