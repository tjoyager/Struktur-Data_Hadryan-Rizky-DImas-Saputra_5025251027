/*
Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027

Program: Deklarasi dan pemanggilan/pencetakan array di cpp
*/


#include <iostream>
using namespace std;

int main(void) {
    int myArr[] = {2, 4, 6, 8};
    
    int i;
    for(i = 0; i < 4; i++) {
        cout << myArr[i] << endl;
    }

    return 0;
}