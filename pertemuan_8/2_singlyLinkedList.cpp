// Singly Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL; // awal, head kosong
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void print() {
        Node* current = head;

        if(current == NULL) {
            cout << "Linked List kosong\n";
            return;
        }

        while(current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main(void) {
    LinkedList data;

    data.insert(10);
    data.insert(20);
    data.insert(30);

    data.print();

    return 0;
}