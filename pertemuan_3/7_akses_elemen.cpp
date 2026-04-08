/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Mengakses elemen pada array
*/

#include <iostream>
using namespace std;

int main(void) {
    int arr[2][2] = {
        {12, 89},
        {90, 76}
    };

    cout << "Array: " << endl;

    int i, j;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << endl;

    cout << "Elemen di baris ke-1 kolom ke-1: " << arr[0][0] << endl;

    cout << "Elemen di baris ke-2 kolom ke-2: " << arr[1][1] << endl;

    return 0;
}