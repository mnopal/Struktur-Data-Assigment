 <h1 align="center">Laporan Praktikum Modul Abstract data type </h1>
<p align="center">MUHAMMAD NAUFAL</p>

## Dasar Teori

ADT adalah definisi tipe data (TYPE) beserta kumpulan operasi dasar (PRIMITIF) yang dapat dilakukan terhadap tipe tersebut. ADT bersifat abstrak dan statik, artinya hanya mendefinisikan apa yang bisa dilakukan, bukan bagaimana cara dilakukan.

Komponen Utama ADT:

1.TYPE (Tipe Data) – struktur data yang didefinisikan oleh pengguna.
Contoh: WAKTU terdiri dari JAM dan TANGGAL, atau GARIS terdiri dari dua POINT.

2.PRIMITIF (Operasi Dasar) – fungsi/prosedur yang bisa dilakukan terhadap TYPE tersebut, meliputi:

 -Konstruktor/Kreator → membuat objek baru (Make...)
 
 -Selector → mengambil komponen dari objek (Get...)
 
 -Mutator/Modifier → mengubah nilai komponen (Set...)
 
 -Validator → memeriksa validitas nilai
 
 -Destruktor → menghapus objek dan membebaskan memori
 
 -Baca/Tulis → interaksi dengan input/output
 
 -Operator Relasional & Aritmatika → membandingkan atau mengoperasikan objek
 
 -Konversi → ubah antara tipe dasar dan tipe ADT
 
 Struktur Implementasi ADT :

1.ADT biasanya terdiri dari dua modul utama dan satu modul driver:

2.Header (.h)
Berisi spesifikasi tipe dan deklarasi fungsi/prosedur (tanpa implementasi).

3.Body (.c / .cpp)
Berisi realisasi dari fungsi/prosedur sesuai spesifikasi.

4.Driver (main program)
Digunakan untuk menguji dan menggunakan ADT.

jadi ADT mendefinisikan data dan operasi secara konseptual (abstrak) tanpa memikirkan detail implementasinya.
Dalam implementasi (misalnya di C/C++), ADT diterjemahkan menjadi struct + fungsi/prosedur,
agar kode menjadi terstruktur, modular, dan mudah dipelihara.

## Guided 

### 1. Mhasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct  mahasiswa {
    /* data */
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
Program ini bertindak sebagai file header. Didalam program ini mendefinisikan struct mahasiswa yang berisi variabel untuk nim, nilai1, dan nilai2. Selain itu, file ini mendeklarasikan fungsi dan prosedur yang beroperasi pada struct tersebut, yaitu void inputMhs() dan float rata2().

### 2. Mahasiswa.cpp
```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m) {
    cout << "Input nim = ";
    cin >> (m).nim;
    cout << "Input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}
```
Program ini berisi implementasi atau kode Program (body) dari fungsi-fungsi yang telah dideklarasikan sebelumnya di mahasiswa.h . Prosedur inputMhs() digunakan untuk meminta input dari pengguna dan menyimpannya ke dalam variabel struct mahasiswa.

### 3. Main.cpp
```C++
// testing
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai = " << rata2(mhs) << endl;
    return 0;
}
```
Program ini merupakan yang utama menggunakan ADT mahasiswa. File ini meng-include "mahasiwa.h" agar dapat mengenali struct dan fungsi yang telah kita buat. Di dalam main(), telah dibuat sebuah objek mhs dari struct mahasiswa, memanggil prosedur inputMhas() untuk mengisi data, yang terakhir akan memanggil fungsi rata2() untuk menampilkan hasil dari perhitungan rata-rata.


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
<img width="1781" height="135" alt="image" src="https://github.com/user-attachments/assets/05cd34aa-56b1-4cf2-8a10-27aa90a1607c" />

```c++
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

```

### OUTPUT
<img width="1391" height="410" alt="image" src="https://github.com/user-attachments/assets/751fd867-4d24-4898-9983-d319cdfd13e3" />

Program ini memperlihatkan dua konsep penting dalam C++:
-Pointer → Mengakses dan memodifikasi data melalui alamat memori (*x, &a).
-Reference → Mengakses dan memodifikasi data secara langsung dengan nama lain dari variabel yang sama (int &x).
keduanya dapat mengubah nilai asli dari variabel yang dikirim ke fungsi, tapi reference lebih sederhana digunakan, sedangkan pointer lebih fleksibel dalam menggunakan alamat memori.

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/66654ee9-17d7-4854-a021-b3429794a3f3" />

### 3. SOAL.3
<img width="1814" height="825" alt="image" src="https://github.com/user-attachments/assets/f17fa8a6-c1fc-4408-b9a4-9bf7d9890732" />

```C++
#include <iostream>
using namespace std;

// Fungsi mencari nilai maksimum
int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

// Fungsi mencari nilai minimum
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// Prosedur menghitung rata-rata
void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    cout << "Nilai rata-rata = " << total / n << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n === menu program array ===" << endl;
        cout << "1. tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. hitung nilai rata-rata" << endl;
        cout << "5. keluar" << endl;
        cout << "pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan! Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid, monggoh coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}

```

### OUTPUT
<img width="1383" height="1024" alt="image" src="https://github.com/user-attachments/assets/d9174664-2662-4de4-bca6-20f9e28cf114" />

<img width="1170" height="654" alt="image" src="https://github.com/user-attachments/assets/1e42bde7-442b-432c-9457-f73f0adbad7b" />


Program ini berfungsi untuk mengolah data pada array satu dimensi — tepatnya untuk:
1.Menampilkan isi array
2.Mencari nilai maksimum
3.Mencari nilai minimum
4.Menghitung nilai rata-rata
Program menggunakan fungsi (function) untuk operasi pencarian nilai dan perhitungan, serta struktur switch–case agar pengguna bisa memilih menu yang diinginkan.
Program diatas juga memperlihatkan cara menggunakan fungsi dan prosedur untuk mengolah data array satu dimensi.
Dengan menggunakan switch–case, program menjadi interaktif dan fleksibel, serta user dapat memilih apakah ingin melihat isi array, mencari nilai tertinggi, terendah, atau rata-ratanya.

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/60e5fc9d-9f96-4db6-91e2-ad70e4479753" />


## Kesimpulan
ringkasan dari modul ini menunjukkan penerapan array satu dimensi dan penggunaan fungsi serta prosedur dalam bahasa C++. Melalui fungsi cariMaksimum() dan cariMinimum(), program dapat menemukan nilai tertinggi dan terendah dalam array, sedangkan prosedur hitungRataRata() digunakan untuk menghitung rata-rata dari seluruh elemen array. Struktur switch–case dimanfaatkan untuk membuat menu yang memudahkan user memilih operasi yang diinginkan, seperti menampilkan isi array, mencari nilai maksimum, minimum, atau menghitung rata-rata. Secara keseluruhan, program ini melatih pemahaman tentang cara mengolah data array menggunakan fungsi, perulangan, dan percabangan, serta memperkuat konsep dasar dalam bahasa C++.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

