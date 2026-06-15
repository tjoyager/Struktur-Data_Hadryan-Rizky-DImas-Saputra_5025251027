/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Input dan Output Nilai di dalam Array
*/

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "Masukkan isi array: ";
    cin >> n;

    int arr[n];

    int i;
    for(i = 0; i < n; i++) {
        cout << "Masukkan bilangan ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nBilangan yang dimasukkan: " << endl;

    for(i = 0; i < n; i++) {
        cout << "Bilangan ke-" << i + 1 << ": " << arr[i] << endl;
    }

    return 0;

}