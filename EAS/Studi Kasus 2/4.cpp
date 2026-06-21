#include <bits/stdc++.h>
using namespace std;

struct NodeFolder {
    string nama;
    bool isFile;
    vector<NodeFolder*> children;
};

NodeFolder* buatNode(string nama, bool isFile = false) {
    NodeFolder* newNode = new NodeFolder();
    newNode->nama = nama;
    newNode->isFile = isFile;
    return newNode;
}

NodeFolder* insertNode(NodeFolder* parent, string nama, bool isFile = false) {
    NodeFolder* newNode = buatNode(nama, isFile);
    parent->children.push_back(newNode);
    cout << "[Folder] Membuat \"" << nama << "\" di dalam \"" << parent->nama << "\"\n";
    return newNode;
}

void deleteNode(NodeFolder* parent, string nama) {
    for (size_t i = 0; i < parent->children.size(); i++) {
        if (parent->children[i]->nama == nama) {
            cout << "[Folder] Menghapus \"" << nama << "\" dari \"" << parent->nama << "\"\n";
            delete parent->children[i];
            parent->children.erase(parent->children.begin() + i);
            return;
        }
    }
    cout << "[Folder] \"" << nama << "\" tidak ditemukan di \"" << parent->nama << "\"\n";
}

void traversal(NodeFolder* node, int level = 0) {
    if (node == nullptr) return;

    for (int i = 0; i < level; i++) cout << "    ";
    cout << (node->isFile ? "[File] " : "[Folder] ") << node->nama << "\n";

    for (NodeFolder* child : node->children) {
        traversal(child, level + 1);
    }
}

int main(void) {
    cout << "=== STRUKTUR FOLDER KOMPUTER (TREE) ===\n\n";

    NodeFolder* root = buatNode("Root");

    NodeFolder* dokumen = insertNode(root, "Dokumen");
    insertNode(dokumen, "Tugas.docx", true);
    insertNode(dokumen, "Skripsi.docx", true);

    NodeFolder* gambar = insertNode(root, "Gambar");
    insertNode(gambar, "Foto.png", true);
    insertNode(gambar, "Logo.png", true);

    cout << "\n=== Struktur Folder Saat Ini ===\n";
    traversal(root);

    cout << "\n";
    deleteNode(dokumen, "Tugas.docx");

    cout << "\n=== Struktur Folder Setelah Penghapusan ===\n";
    traversal(root);

    return 0;
}
