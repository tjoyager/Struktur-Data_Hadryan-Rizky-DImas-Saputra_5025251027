// Singly Circular Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class singlyCircularLL {
private:
    Node* head;

public:
    singlyCircularLL() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->data = x;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while(temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    void print() {
        if(head == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        Node* now = head;

        do {
            cout << now->data << " -> ";
            now = now->next;
        } while(now != head);

        cout << "(back to " << head->data << ")" << endl;
    }
};

int main(void) {
    singlyCircularLL data;

    data.insert(10);
    data.insert(20);
    data.insert(30);

    data.print();

    return 0;
}