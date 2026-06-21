#include <bits/stdc++.h>
using namespace std;

struct NodeLagu {
    string judul;
    NodeLagu* prev;
    NodeLagu* next;
};

NodeLagu* headPlaylist = nullptr;
NodeLagu* tailPlaylist = nullptr;
NodeLagu* laguSekarang = nullptr;

void insertLagu(string judul) {
    NodeLagu* newNode = new NodeLagu{judul, nullptr, nullptr};

    if (headPlaylist == nullptr) {
        headPlaylist = tailPlaylist = newNode;
        laguSekarang = newNode;
    } else {
        newNode->prev = tailPlaylist;
        tailPlaylist->next = newNode;
        tailPlaylist = newNode;
    }

    cout << "[Playlist] Menambahkan lagu: " << judul << "\n";
}

void deleteLagu(string judul) {
    NodeLagu* temp = headPlaylist;

    while (temp != nullptr && temp->judul != judul) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "[Playlist] Lagu \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    if (temp->prev != nullptr) temp->prev->next = temp->next;
    else headPlaylist = temp->next;

    if (temp->next != nullptr) temp->next->prev = temp->prev;
    else tailPlaylist = temp->prev;

    if (laguSekarang == temp) {
        laguSekarang = (temp->next != nullptr) ? temp->next : temp->prev;
    }

    cout << "[Playlist] Menghapus lagu: " << judul << "\n";
    delete temp;
}

void next() {
    if (laguSekarang == nullptr) {
        cout << "[Playlist] Playlist kosong.\n";
        return;
    }
    if (laguSekarang->next == nullptr) {
        cout << "[Playlist] Sudah di lagu terakhir.\n";
        return;
    }
    laguSekarang = laguSekarang->next;
    cout << "[Playlist] Memutar (Next): " << laguSekarang->judul << "\n";
}

void previous() {
    if (laguSekarang == nullptr) {
        cout << "[Playlist] Playlist kosong.\n";
        return;
    }
    if (laguSekarang->prev == nullptr) {
        cout << "[Playlist] Sudah di lagu pertama.\n";
        return;
    }
    laguSekarang = laguSekarang->prev;
    cout << "[Playlist] Memutar (Previous): " << laguSekarang->judul << "\n";
}

void tampilkanPlaylist() {
    cout << "\n=== Isi Playlist ===\n";
    NodeLagu* temp = headPlaylist;
    while (temp != nullptr) {
        cout << " - " << temp->judul;
        if (temp == laguSekarang) cout << "  (sedang diputar)";
        cout << "\n";
        temp = temp->next;
    }
}

int main(void) {
    cout << "=== PLAYLIST MUSIK (DOUBLY LINKED LIST) ===\n\n";

    insertLagu("Lagu A");
    insertLagu("Lagu B");
    insertLagu("Lagu C");

    tampilkanPlaylist();

    cout << "\n";
    next();
    next();
    previous();

    cout << "\n";
    deleteLagu("Lagu C");

    tampilkanPlaylist();

    return 0;
}
