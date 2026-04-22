// Double Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLL {
private:
    Node* head;
    Node* tail;

public:
    DoublyLL() {
        head = NULL;
        tail = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printForward() {
        Node* now = head;

        if(now == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        cout << "Print Maju: NULL <- ";

        while(now != NULL) {
            cout << now->data;
            
            if(now->next != NULL) {
                cout << " <-> ";
            }
            now = now->next;
        }
        cout << " -> NULL\n";
    }

    void printBackward() {
        Node* now = tail;

        if(now == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        cout << "Print Mundur: NULL <- ";

        while(now != NULL) {
            cout << now->data;

            if(now->prev != NULL) {
                cout << " <-> ";
            }
            now = now->prev;
        }
        cout << " -> NULL\n";
    }
};

int main(void) {
    DoublyLL data;

    data.insert(10);
    data.insert(20);
    data.insert(30);

    data.printForward();
    data.printBackward();

    return 0;
}