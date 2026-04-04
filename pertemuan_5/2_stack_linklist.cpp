#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top= NULL;
        }

        // push
        void push(int x) {
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = top;
            top = newNode;

            cout << x << " ditambahkan ke Stack\n";
        }

        // pop
        void pop() {
            if(top == NULL) {
                cout << "Stack Underflow\n";
                return;
            }

            Node* temp = top;
            cout << temp->data << " dihapus dari Stack\n";
            top = top->next;
            delete temp;
        }

        // peek 
        void peek() {
            if(top == NULL) {
                cout << "Stack Kosong\n";
            } else {
                cout << "Elemen Paling Atas: " << top->data << endl;
            }
        }

        // cek empty
        bool isEmpty() {
            return(top == NULL);
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