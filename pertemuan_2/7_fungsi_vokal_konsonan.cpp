// Program: Huruf Vokal atau Konsonan

#include <iostream>
using namespace std;

void fungsi(char t) {
    if(t == 'a' || t == 'A' ||
        t == 'i' || t == 'I' ||
        t == 'u' || t == 'U' ||
        t == 'e' || t == 'E' ||
        t == 'o' || t == 'O') {
        cout << "Huruf Vokal" << '\n';
    } else {
        cout << "Huruf Konsonan" << '\n';
    }
}

int main(void) {
    char s;
    cout << "Masukkan Huruf: ";
    cin >> s;

    fungsi(s);

    return 0;
}