#include <bits/stdc++.h>
using namespace std;

struct NodeAksi {
    string aksi;
    NodeAksi* next;
};

NodeAksi* topUndo = nullptr;
NodeAksi* topRedo = nullptr;

void push(NodeAksi*& top, string aksi) {
    NodeAksi* newNode = new NodeAksi{aksi, top};
    top = newNode;
}

string pop(NodeAksi*& top) {
    if (top == nullptr) return "";

    NodeAksi* temp = top;
    string aksi = temp->aksi;

    top = top->next;
    delete temp;

    return aksi;
}

string peek(NodeAksi* top) {
    if (top == nullptr) return "(kosong)";
    return top->aksi;
}

bool isEmpty(NodeAksi* top) {
    return top == nullptr;
}

void ketik(string teks) {
    push(topUndo, "Tambah \"" + teks + "\"");
    while (!isEmpty(topRedo)) {
        pop(topRedo);
    }
    cout << "[Editor] Mengetik: " << teks << "\n";
}

void undo() {
    if (isEmpty(topUndo)) {
        cout << "[Editor] Tidak ada aksi untuk di-undo.\n";
        return;
    }

    string aksi = pop(topUndo);
    push(topRedo, aksi);
    cout << "[Editor] Undo: " << aksi << "\n";
}

void redo() {
    if (isEmpty(topRedo)) {
        cout << "[Editor] Tidak ada aksi untuk di-redo.\n";
        return;
    }

    string aksi = pop(topRedo);
    push(topUndo, aksi);
    cout << "[Editor] Redo: " << aksi << "\n";
}

int main(void) {
    cout << "=== SISTEM UNDO/REDO TEXT EDITOR ===\n\n";

    ketik("A");
    ketik("B");
    ketik("C");

    cout << "\nAksi teratas saat ini: " << peek(topUndo) << "\n\n";

    undo();
    undo();

    cout << "\nAksi teratas Undo Stack: " << peek(topUndo) << "\n";
    cout << "Aksi teratas Redo Stack: " << peek(topRedo) << "\n\n";

    redo();

    cout << "\nAksi teratas Undo Stack setelah redo: " << peek(topUndo) << "\n";

    return 0;
}
