#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    cout << "Masukkan elemen matriks A:\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << endl;

    cout << "masukkan matriks B:\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\n hasil \n\n";

    cout << "hasil Penjumlahan (A + B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nhasil Pengurangan (A - B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nhasil Perkalian (A * B):\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
