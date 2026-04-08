// Program: Mencari nilai minimum dan maximum dari sebuah Array

#include <iostream>
using namespace std;

int cariMin(int arr[], int n) {
    int hasil = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < hasil) {
            hasil = arr[i];
        }
    }

    return hasil;
}

int cariMax(int arr[], int n) {
    int hasil = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > hasil) {
            hasil = arr[i];
        }
    }

    return hasil;
}

int main() {
    int n, arr[100];

    cout << "Masukkan Jumlah Bilangan: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Masukkan Bilangan Ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Nilai Minimum: " << cariMin(arr, n) << endl;
    cout << "Nilai Maksimum: " << cariMax(arr, n) << endl;

    return 0;
}