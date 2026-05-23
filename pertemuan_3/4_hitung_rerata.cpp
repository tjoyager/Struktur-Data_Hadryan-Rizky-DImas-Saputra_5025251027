/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Menghitung nilai rata-rata Mahasiswa
*/

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "Masukkan banyak nilai: ";
    cin >> n;
    
    int nilai[n];
    int tot_nilai = 0;
    float rerata;

    int i;
    for(i = 0; i < n; i++) {
        cout << "Masukkan nilai Mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
        tot_nilai += nilai[i];
    }

    rerata = (float)tot_nilai / n;

    cout << "\nTotal Nilai: " << tot_nilai << endl;
    cout << "Rata-rata: " << rerata << endl;

    return 0;
}