#include <iostream>
using namespace std;

int main(void) {
    int baris, kolom, no = 1, n = 5;

    for(baris = 0; kolom <= n; baris++) {
        for(kolom = 0; kolom < baris; kolom++) {
            cout << no << ' ';
            no++;
        }

        cout << '\n';
    }

    return 0;
} 