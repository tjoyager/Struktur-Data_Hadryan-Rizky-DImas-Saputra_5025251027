#include <bits/stdc++.h>
using namespace std;

int faktorial(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main(void) {
    int a;
    cout << "Masukkan Bilangan: ";
    cin >> a;

    cout << '\n' << faktorial(a);

    return 0;
}