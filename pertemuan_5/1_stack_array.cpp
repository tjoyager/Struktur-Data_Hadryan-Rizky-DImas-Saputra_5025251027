#include <bits/stdc++.h>
using namespace std;

#define max 5

class Stack {

    private:
        int arr[max];
        int top;

    public:
        // stack kosong
        Stack() {
            top = -1;
        }

        // push
        void push(int x) {
            if(top == max - 1) {
                cout << "Stack Overflow\n";
            } else {
                arr[++top] = x;
                cout << x << " ditambahkan ke Stack\n";
            }
        }

        // pop
        void pop() {
            if(top == -1) {
                cout << "Stack Underflow\n";
            } else {
                cout << arr[top--] << " dihapus dari Stack\n";
            }
        }

        // peek
        void peek() {
            if(top == -1) {
                cout << "Stack Kosong\n";
            } else {
                cout << "Element Paling Atas: " << arr[top] << endl;
            }
        }
};

int main(void) {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}
