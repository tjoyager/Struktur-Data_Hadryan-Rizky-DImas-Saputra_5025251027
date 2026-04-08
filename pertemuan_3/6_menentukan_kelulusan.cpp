/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Menentukan kelulusan mahasiswa berdasarkan input nilai
*/

#include <iostream>
using namespace std;

int main(void) {
    int nilai[5];

    int i;
    for(i = 0; i < 5; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i]; 
    }

    cout << "\nStatus Kelulusan: " << endl;

    for(i = 0; i < 5; i++) {
        if(nilai[i] >= 75) {
            cout << "Mahasiswa ke-" << i + 1 << " LULUS" << endl;
        } else {
            cout << "Mahasiswa ke-" << i + 1 << " TIDAK LULUS" << endl;
        }
    }

    return 0;
}