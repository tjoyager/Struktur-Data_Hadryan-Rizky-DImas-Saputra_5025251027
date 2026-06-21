#include <bits/stdc++.h>
using namespace std;

struct NodePasien {
    string nama;
    NodePasien* next;
};

NodePasien* frontQueue = nullptr;
NodePasien* rearQueue = nullptr;

void enqueue(string nama) {
    NodePasien* newNode = new NodePasien{nama, nullptr};

    if (rearQueue == nullptr) {
        frontQueue = rearQueue = newNode;
    } else {
        rearQueue->next = newNode;
        rearQueue = newNode;
    }

    cout << "[Antrian] " << nama << " mendaftar dan masuk antrian.\n";
}

void dequeue() {
    if (frontQueue == nullptr) {
        cout << "[Antrian] Tidak ada pasien dalam antrian.\n";
        return;
    }

    NodePasien* temp = frontQueue;
    cout << "[Antrian] Memanggil pasien: " << frontQueue->nama << "\n";

    frontQueue = frontQueue->next;
    if (frontQueue == nullptr) rearQueue = nullptr;

    delete temp;
}

void front() {
    if (frontQueue == nullptr) {
        cout << "[Antrian] Antrian kosong.\n";
        return;
    }
    cout << "[Antrian] Pasien berikutnya: " << frontQueue->nama << "\n";
}

bool isEmpty() {
    return frontQueue == nullptr;
}

int main(void) {
    cout << "=== SISTEM ANTRIAN RUMAH SAKIT ===\n\n";

    enqueue("Andi");
    enqueue("Budi");
    enqueue("Citra");

    cout << "\n";
    front();

    cout << "\n";
    while (!isEmpty()) {
        dequeue();
    }

    cout << "\n";
    dequeue();

    return 0;
}
