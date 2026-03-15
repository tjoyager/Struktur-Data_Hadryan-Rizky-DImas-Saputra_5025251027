/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Mencari Nilai Maksimal dalam array
*/

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "Masukkan banyak nilai: ";
    cin >> n;

    int nilai[n];
    int i;
    for(i = 0; i < n; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    int maks = nilai[0];

    for(i = 0; i < n; i++) {
        if(nilai[i] > maks) {
            maks = nilai[i];
        }
    }

    cout << "\nNilai tertinggi mahasiswa tersebut adalah " << maks << endl;

    return 0;
}