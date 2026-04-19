#include <bits/stdc++.h>
#define max 5
using namespace std;

class Queue {
    private:
        int arr[max];
        int front, rear;

    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            return (front == -1);
        }

        bool isFull() {
            return (rear == max - 1);
        }

        void enqueue(int x) {
            if(isFull()) {
                cout << "Queue Overflow\n";
                return;
            }

            if(isEmpty()) {
                front = 0;
            }

            arr[++rear] = x;
            cout << "Elemen " << x << " masuk ke Queue\n";
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Queue Underflow\n";
                return;
            }

            cout << "Elemen " << arr[front] << " keluar ke Queue\n";

            if(front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }

        void display() {
            if(isEmpty()) {
                cout << "Queue kosong\n";
                return;
            }

            cout << "Isi Queue: ";

            int i;
            for(i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }  
};

int main(void) {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}