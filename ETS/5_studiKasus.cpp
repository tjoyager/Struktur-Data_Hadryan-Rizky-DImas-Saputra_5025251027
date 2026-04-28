/*

Nama: Hadryan Rizky Dimas Saputra
NRP: 5025251027
Kelas: Struktur Data (D)
Soal: ETS Nomor 5 (Studi Kasus menggunakan Queue)

*/

#include <bits/stdc++.h>
#define max 100

using namespace std;

class Queue {
    private:
        string arr[max];
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

        void enqueue(string nama) {
            if(isFull()) {
                cout << "Antrian Penuh!\n";
                return;
            }

            if(isEmpty()) {
                front = 0;
            }

            arr[++rear] = nama;
            cout << "[Enqueue] " << nama << " mengambil nomor antrian.\n";
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Antrian Kosong!\n";
                return;
            }

            cout << "[Dequeue] Memanggil dan melayani: " << arr[front] << "\n";

            if(front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }

        void display() {
            if(isEmpty()) {
                cout << "\nStatus: Antrian Kosong\n";
                return;
            }

            cout << "\n=== Status Antrean ===\n";
            cout << "Sedang dilayani (Front) : " << arr[front] << "\n";
            cout << "Antrian terakhir (Rear) : " << arr[rear] << "\n";
            cout << "Daftar antrian          : ";
            
            for(int i = front; i <= rear; i++) {
                cout << arr[i];
                if (i < rear) cout << " -> ";
            }
            cout << endl;
        }  
};

int main(void) {
    Queue q;

    cout << "=== 1 ===\n";
    q.enqueue("Mahasiswa A");
    q.enqueue("Mahasiswa B");
    q.enqueue("Mahasiswa C");
    q.display();

    cout << "\n=== 2 ===\n";
    q.dequeue();
    q.display();

    cout << "\n=== 3 ===\n";
    q.enqueue("Mahasiswa D");
    q.display();

    cout << "\n=== 4 ===\n";
    q.display();

    return 0;
}