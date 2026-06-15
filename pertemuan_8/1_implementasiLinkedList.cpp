// Implementasi Linked List pada C++

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

int main(void) {
    node* node1 = new node();
    node* node2 = new node();
    node* node3 = new node();

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node* current = node1;

    while(current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL";

    return 0;
}
