#include <bits/stdc++.h>
using namespace std;

struct NodeBST {
    int nim;
    string nama;
    NodeBST* left;
    NodeBST* right;
};

NodeBST* rootBST = nullptr;

NodeBST* buatNode(int nim, string nama) {
    NodeBST* newNode = new NodeBST();
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

NodeBST* insert(NodeBST* node, int nim, string nama) {
    if (node == nullptr) {
        return buatNode(nim, nama);
    }

    if (nim < node->nim) {
        node->left = insert(node->left, nim, nama);
    } else if (nim > node->nim) {
        node->right = insert(node->right, nim, nama);
    }

    return node;
}

NodeBST* search(NodeBST* node, int nim) {
    if (node == nullptr || node->nim == nim) {
        return node;
    }

    if (nim < node->nim) return search(node->left, nim);
    return search(node->right, nim);
}

NodeBST* cariMin(NodeBST* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

NodeBST* deleteNode(NodeBST* node, int nim) {
    if (node == nullptr) return nullptr;

    if (nim < node->nim) {
        node->left = deleteNode(node->left, nim);
    } else if (nim > node->nim) {
        node->right = deleteNode(node->right, nim);
    } else {

        if (node->left == nullptr) {
            NodeBST* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            NodeBST* temp = node->left;
            delete node;
            return temp;
        }

        NodeBST* successor = cariMin(node->right);
        node->nim = successor->nim;
        node->nama = successor->nama;
        node->right = deleteNode(node->right, successor->nim);
    }

    return node;
}

void inOrder(NodeBST* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << "NIM: " << node->nim << " - Nama: " << node->nama << "\n";
    inOrder(node->right);
}

int main(void) {
    cout << "=== SISTEM PENCARIAN DATA MAHASISWA (BST) ===\n\n";

    rootBST = insert(rootBST, 50, "Mahasiswa-50");
    rootBST = insert(rootBST, 30, "Mahasiswa-30");
    rootBST = insert(rootBST, 70, "Mahasiswa-70");
    rootBST = insert(rootBST, 20, "Mahasiswa-20");
    rootBST = insert(rootBST, 40, "Mahasiswa-40");
    rootBST = insert(rootBST, 60, "Mahasiswa-60");
    rootBST = insert(rootBST, 80, "Mahasiswa-80");

    cout << "Data mahasiswa terurut berdasarkan NIM:\n";
    inOrder(rootBST);

    cout << "\n";
    int cariNim = 60;
    NodeBST* hasil = search(rootBST, cariNim);
    if (hasil != nullptr) {
        cout << "[Pencarian] NIM " << cariNim << " ditemukan: " << hasil->nama << "\n";
    } else {
        cout << "[Pencarian] NIM " << cariNim << " tidak ditemukan.\n";
    }

    cout << "\n[Hapus] Menghapus data dengan NIM 30\n";
    rootBST = deleteNode(rootBST, 30);

    cout << "\nData mahasiswa setelah penghapusan:\n";
    inOrder(rootBST);

    return 0;
}
