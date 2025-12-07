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

### 1. Mahasiswa.h

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
<img width="1964" height="208" alt="image" src="https://github.com/user-attachments/assets/9d404045-85cb-4ea6-b9d2-007868d6cb35" />
 

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10) {
        n = 10;
        cout << "Jumlah dibatasi menjadi 10.\n";
    }

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir pakai fungsi
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Output data
    cout << "\n===== Data Mahasiswa =====\n";
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```
#### Output:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/ea85044f-c08e-4e6a-8fd1-491abf49c8b2" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/92b95bee-3c8c-4593-b264-9d68b3370a18" />

Program ini digunakan untuk mengelola data akademik mahasiswa dengan menyimpan informasi ke dalam array bertipe struktur Mahasiswa. Struktur ini mengelompokkan data penting seperti nama, NIM, nilai UTS, UAS, nilai tugas, dan nilai akhir agar pengolahan data menjadi lebih rapih
Proses perhitungan nilai akhir dilakukan melalui fungsi hitungNilaiAkhir() yang menerima nilai UTS, UAS, dan tugas sebagai parameter, kemudian menghitung hasil berdasarkan bobot 30% UTS, 40% UAS, dan 30% tugas. Hal ini meningkatkan modularitas dan keterbacaan program.
Dalam fungsi main(), pengguna diminta memasukkan jumlah mahasiswa yang akan diproses dengan batas maksimal 10 data. Program kemudian menggunakan perulangan for untuk menginput data, menghitung nilai akhir setiap mahasiswa, dan menampilkan seluruh data yang telah diproses secara terstruktur dan efisien.


#### Full code Screenshot:
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/82c924a5-f6bb-4695-8dcd-950224e3c91f" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/5e14ebc4-9ee1-4b66-93a5-7357dd9b1b56" />


### 2. SOAL.2
<img width="1610" height="1066" alt="image" src="https://github.com/user-attachments/assets/7db4857b-20a6-4f09-bd9d-c9f180aa6f1e" />


### pelajaran.h
```c++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi fungsi
pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

```
### pelajaran.cpp
```c++
#include <iostream>
#include "pelajaran.h"
using namespace std;

// Implementasi fungsi untuk membuat data pelajaran
pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

// Implementasi prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "kode           : " << pel.kodeMapel << endl;
}

```
main.cpp
``` c++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```

### OUTPUT
<img width="1724" height="321" alt="image" src="https://github.com/user-attachments/assets/7501abf3-e2fd-4c90-b591-f20db4164110" />

1. pelajaran.h

File ini berfungsi sebagai header file yang berisi definisi ADT (Abstract Data Type) pelajaran. Di dalamnya terdapat deklarasi struktur data yang menyimpan atribut namaMapel dan kodeMapel. Selain itu, file ini juga berisi deklarasi fungsi create_pelajaran() dan prosedur tampil_pelajaran(). Tujuan penggunaan file ini adalah untuk menyediakan antarmuka (interface) yang dapat digunakan oleh file lain tanpa perlu mengetahui detail implementasinya.

2. pelajaran.cpp

File ini merupakan file implementasi dari fungsi-fungsi yang telah dideklarasikan di dalam pelajaran.h. Di dalamnya terdapat definisi fungsi create_pelajaran() yang bertugas membuat dan menginisialisasi objek bertipe pelajaran, serta prosedur tampil_pelajaran() yang bertugas menampilkan isi data pelajaran ke layar. File ini berfungsi untuk memisahkan logika program dari deklarasi struktur datanya.

3. main.cpp

File ini merupakan file utama program yang berisi fungsi main() sebagai titik awal eksekusi program. Di dalamnya, objek pelajaran dibuat melalui pemanggilan fungsi create_pelajaran() dan hasilnya ditampilkan menggunakan prosedur tampil_pelajaran(). File ini berperan sebagai pengguna (user) dari ADT pelajaran, sehingga program menjadi lebih terstruktur dan modular.

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/c7e98820-3191-46a3-92f1-4fc15f4533e3" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/d386d2ff-ef5c-477f-8f31-98e5600a3bfd" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/657239e4-f48d-46f4-96e1-578c34ed86e4" />



### 3. SOAL.3
<img width="1504" height="839" alt="image" src="https://github.com/user-attachments/assets/d83fc800-284d-415f-93ba-ac61f7b78d82" />


```C++
#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) { //baris
        for (int j = 0; j < 3; j++) { // kolom 
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemenArray(int arrSatu[3][3], int arrDua[3][3], int baris, int kolom) {
    int temp = arrSatu[baris][kolom];
    arrSatu[baris][kolom] = arrDua[baris][kolom];
    arrDua[baris][kolom] = temp;
}

void tukarViaPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arraySatu2D[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arrayDua2D[3][3] = {
        {20,25,40},
        {25,45,55},
        {10,35,15}
    };

    cout << "--Isi Array Awal Sebelum ubah--" << endl;
    cout << "Isi Array Pertama: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nIsi Array Kedua: " << endl;
    tampilkanArray(arrayDua2D);

    //Tukar elemen dengan indeks arr
    tukarElemenArray(arraySatu2D, arrayDua2D, 1, 1); // note ini bukan baris 1 kolom satu tapi baris 2 kolom 2, array mulai dari 0
    cout << "\n--Setelah menukar elemen di [1][1]--" <<endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "Array Dua" << endl;
    tampilkanArray(arrayDua2D);

    // pointer
    int *ptrA;
    int *ptrB;

    ptrA = &arraySatu2D[0][0]; // simpan alamat 1 (baris 1 kolom 1)
    ptrB = &arrayDua2D[2][2]; // simpan alamat 50 (baris 3 kolom 3)

    cout << "\n--Menukar nilai via pointer--" << endl;
    cout << "Nilai yang ditunjuk pointerA(sebelum): " << *ptrA << endl;
    cout << "Nilai yang ditunjuk pointerB(sebelum): " << *ptrB << endl;

     tukarViaPointer(ptrA, ptrB);

    cout << "\nNilai yang ditunjuk pointerA (setelah): " << *ptrA << endl; // Akan menampilkan 50
    cout << "Nilai yang ditunjuk pointerB (setelah): " << *ptrB << endl; // Akan menampilkan 1

    cout << "\nIsi Array Final Setelah Semua Penukaran " << endl;
    cout << "Array Satu: " << endl;
    tampilkanArray(arraySatu2D);
    cout << "\nArray Dua: " << endl;
    tampilkanArray(arrayDua2D);

}
```

### OUTPUT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/0b07e0c0-9fa1-4be6-a6de-23de205627cb" />

Program ini berfungsi untuk mendemonstrasikan penggunaan array dua dimensi, fungsi/prosedur, dan konsep pointer dalam bahasa pemrograman C++. Program menggunakan dua buah array integer berukuran 3×3 sebagai struktur data utama.

Fungsi tampilArray() berperan untuk menampilkan seluruh elemen array dua dimensi ke layar. Proses ini dilakukan menggunakan perulangan bersarang untuk mengakses setiap baris dan kolom secara sistematis.

Fungsi tukarArray() berfungsi untuk menukar nilai pada posisi tertentu antara dua array dua dimensi. Proses pertukaran dilakukan dengan memanfaatkan variabel sementara agar nilai tidak hilang selama proses pertukaran berlangsung.

Fungsi tukarPointer() digunakan untuk menukar nilai dari dua variabel melalui mekanisme pointer. Dengan menggunakan pointer, fungsi dapat mengakses dan memodifikasi langsung nilai variabel yang berada pada alamat memori tertentu.

Pada fungsi main(), program melakukan inisialisasi dua array dua dimensi beserta dua variabel integer. Selain itu, dibuat pula dua pointer yang menunjuk ke alamat variabel tersebut. Program kemudian menampilkan isi array, melakukan pertukaran elemen tertentu antar array, serta melakukan pertukaran nilai variabel melalui pointer.

### FULL CODE SCREENSHOT
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/833793c7-39a7-4012-946b-f37198a5c465" />
<img width="2560" height="1600" alt="image" src="https://github.com/user-attachments/assets/241c8c4e-4704-4a14-b608-19130e24b7ae" />



## Kesimpulan
kesimpulan pada minggu ketiga praktikum, saya memperoleh pemahaman tentang konsep Abstract Data Type (ADT) dalam C++. ADT membantu membuat program lebih rapi dan terstruktur dengan memisahkan data dan fungsi ke dalam file yang berbeda, sehingga kode menjadi lebih mudah dipahami dan dikelola. Melalui praktikum daring, saya belajar cara membagi program ke dalam file header (.h) dan source (.cpp), yang meningkatkan kemampuan saya dalam menulis program C++ yang lebih modular, terorganisir, dan mudah dikembangkan.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

