/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Mencetak Alamat Array
*/

#include <iostream>
using namespace std;

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};

    int i;
    for(i = 0; i < 5; i++) {
        cout << "Nilai: " << arr[i] << endl;
        cout << "Alamat: " << &arr[i] << endl;
    }

    return 0;
}