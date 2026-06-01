#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    // membuat dynamic array
    int* data = new int[n];

    // input data
    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i+1 << ": ";
        cin >> data[i];
    }

    cout << "\nIsi array:\n";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    // menghapus memori
    delete[] data;

    return 0;
}