// Program: Mencari bilangan prima di antara rentang dua bilangan

#include <iostream>
#include <stdio.h>
using namespace std;

bool prima(int n) {
    if(n <= 1) {
        return false;
    }

    for(int k = 2; k < n; k++) {
        if(n % k == 0) {
            return false;
        }
    }

    return true;
}

void cari(int l, int r) {
    bool temu = false;

    for(int i = l; i <= r; i++) {
        if(prima(i)) {
            printf("%d ", i);
            temu = true;
        }
    }

    if(!temu) {
        printf("Tidak ada bilangan prima");
    }
    printf("\n");
}

int main(void) {
    int l, r;

    cout << "Masukkan Bilangan Pertama: ";
    cin >> l;
    cout << '\n';

    cout << "Masukkan Bilangan Kedua: ";
    cin >> r;
    cout << '\n';

    cout << "Bilangan Prima: ";
    cari(l, r);

    return 0;
}