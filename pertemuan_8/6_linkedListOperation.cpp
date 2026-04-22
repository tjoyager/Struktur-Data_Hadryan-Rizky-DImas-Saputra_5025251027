// Implementasi operasi dasar pada linked list

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LL {
private:
    Node* head;

public:
    LL() {
        head = NULL;
    }

    void insert_head(int x) {
        Node* newNode = new Node();
        newNode->data = x;

        newNode->next = head;

        head = newNode;
    }

    void insert_tail(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insert_position(int x, int posisi) {
        if(posisi == 1) {
            insert_head(x);
            return;
        }

        Node* newNode = new Node();
        newNode->data = x;

        Node* temp = head;

        int i;
        for(i = 1; i < posisi - 1; i++) {
            if(temp == NULL) {
                cout << "Posisi tidak valid\n";
                return;
            }
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "Posisi tidak valid\n";
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void traverse() {
        if(head == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        Node* temp = head;
        cout << ">> Isi Linked List: ";

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void update(int oldX, int newX) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->data == oldX) {
                temp->data = newX;
                cout << ">> Update: Nilai " << oldX << " berhasil diubah menjadi " << newX << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Nilai " << oldX << " tidak ditemukan\n";
    }

    void search(int x) {
        Node* temp = head;
        int posisi = 1;

        while(temp != NULL) {
            if(temp->data == x) {
                cout << ">> Pencarian: Nilai " << x << " ditemukan di posisi " << posisi << endl;
                return;
            }
            temp = temp->next;
            posisi++;
        }
        cout << "Pencarian " << x << " tidak ditemukan\n";
    }

    void remove(int x) {
        if(head == NULL) {
            cout << "Linked List kosong (tidak dapat menghapus)\n";
            return;
        }

        if(head->data == x) {
            Node* nodeDelete = head;
            head = head->next;
            delete nodeDelete;

            cout << ">> Menghapus: Nilai " << x << " (Head) berhasil dihapus\n";
            return; 
        }

        Node* now = head;
        Node* prev = NULL;

        while(now != NULL && now->data != x) {
            prev = now;
            now = now->next;
        }

        if(now == NULL) {
            cout << "Nilai " << x << " tidak ditemukan (tidak dapat menghapus)\n";
            return;
        }

        prev->next = now->next;
        delete now;
        cout << ">> Menghapus: Nilai " << x << " berhasil dihapus\n";
    }
};

int main(void) {
    LL data;

    cout << "INSERTION\n";
    data.insert_head(10);
    data.insert_tail(40);
    data.insert_position(20, 2);
    data.insert_position(30, 3); 
    data.traverse();

    cout << "\nSEARCHING\n";
    data.search(20);
    data.search(30);
    data.search(70);

    cout << "\nUPDATING\n";
    data.update(20, 25);
    data.update(50, 60);
    data.traverse();

    cout << "\nDELETION\n";
    data.remove(10);
    data.remove(30);
    data.remove(100);
    data.traverse();

    return 0;
}