// Program: Cek ganjil dan genap

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "Masukkan Bilangan: ";
    cin >> n;

    if(n % 2 == 0) {
        cout << "Genap";
    } else {
        cout << "Ganjil";
    }

    return 0;
}