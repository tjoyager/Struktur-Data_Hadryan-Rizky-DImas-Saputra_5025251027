#include <iostream>
using namespace std;

int main(void) {
    int var = 10;

    int* ptr = &var;

    cout << "Nilai dari x: " << var << endl;
    cout << "Alamat dari x: " << &var << endl;
    cout << "Nilai dari ptr: " << ptr << endl;
    cout << "Nilai dari *ptr: " << *ptr << endl;

    return 0;
}