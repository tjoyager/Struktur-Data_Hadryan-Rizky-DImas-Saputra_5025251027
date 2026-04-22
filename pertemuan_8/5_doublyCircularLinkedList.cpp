// Doubly Circular Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyCircularLL {
private:
    Node* head;

public:
    DoublyCircularLL() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->data = x;

        if(head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;

            tail->next = newNode;
            newNode->prev = tail;

            newNode->next = head;
            head->prev = newNode;
        }
    }

    void printForward() {
        if(head == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        Node* now = head;
        cout << "Print Maju: (Lingkar ke belakang) <-> ";

        do {
            cout << now->data;

            if(now->next != head) {
                cout << " <-> ";
            }
            now = now->next;
        } while(now != head);

        cout << " <-> (Lingkar kembali ke " << head->data << ")\n";
    }

    void printBackward() {
        if(head == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        Node* now = head->prev;

        cout << "Print Mundur: (Lingkar ke depan) <-> ";

        do {
            cout << now->data;

            if(now->prev != head->prev) {
                cout << " <-> ";
            }
            now = now->prev;
        } while(now != head->prev);

        cout << " <-> (Lingkar kembali ke " << head->prev->data << ")\n";
    }
};

int main(void) {
    DoublyCircularLL data;

    data.insert(10);
    data.insert(20);
    data.insert(30);

    data.printForward();
    data.printBackward();

    return 0;
}
