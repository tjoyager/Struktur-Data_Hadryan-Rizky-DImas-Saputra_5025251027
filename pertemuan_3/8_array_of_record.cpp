/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Input dan Output Array of Record untuk Mahasiswa
*/

#include <bits/stdc++.h>
using namespace std;

struct mahasiswa
{
    string nrp, nama, jurusan;
    int umur;
    string hobi[3];
};

int main(void) {
    int n;
    cout << "Masukkan banyak mahasiswa: ";
    cin >> n;

    mahasiswa mhs[n];

    int i;
    for(i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << ": " << endl;

        cout << "NRP: ";
        cin >> mhs[i].nrp;

        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);

        cout << "Jurusan: ";
        getline(cin >> ws, mhs[i].jurusan);

        cout << "Umur: ";
        cin >> mhs[i].umur;

        cout << "Masukkan 3 Hobi Mahasiswa: " << endl;
        int j;
        for(j = 0; j < 3; j++) {
            cout << "Hobi ke-" << j + 1 << ": ";
            getline(cin >> ws, mhs[i].hobi[j]);
        }

        cout << endl;
    }

    cout << "\n--- DATA ---" << endl;

    for(i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "NRP        :" << mhs[i].nrp << endl;
        cout << "Nama       :" << mhs[i].nama << endl;
        cout << "Jurusan    :" << mhs[i].jurusan << endl;
        cout << "Umur       :" << mhs[i].umur << endl;

        cout << "Hobi       :" << endl;
        int j;
        for(j = 0; j < 3; j++) {
            cout << "   " << "Hobi ke-" << j + 1 << ": " << mhs[i].hobi[j] << endl;
        }

        cout << endl;
    }

    return 0;
}