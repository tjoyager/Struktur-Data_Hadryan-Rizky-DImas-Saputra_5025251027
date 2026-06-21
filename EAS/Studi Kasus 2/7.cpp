#include <bits/stdc++.h>
using namespace std;

struct NodeAkun {
    string username;
    string password;
    NodeAkun* next;
};

const int HASH_SIZE = 10;
NodeAkun* hashTable[HASH_SIZE];

void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

int hashFunction(string username) {
    int sum = 0;
    for (char c : username) sum += c;
    return sum % HASH_SIZE;
}

void insertAkun(string username, string password) {
    int index = hashFunction(username);
    NodeAkun* newNode = new NodeAkun{username, password, nullptr};

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        NodeAkun* temp = hashTable[index];
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    cout << "[Hash:" << index << "] Akun \"" << username << "\" berhasil didaftarkan.\n";
}

NodeAkun* searchAkun(string username) {
    int index = hashFunction(username);
    NodeAkun* temp = hashTable[index];

    while (temp != nullptr) {
        if (temp->username == username) return temp;
        temp = temp->next;
    }

    return nullptr;
}

void deleteAkun(string username) {
    int index = hashFunction(username);
    NodeAkun* temp = hashTable[index];
    NodeAkun* prev = nullptr;

    while (temp != nullptr && temp->username != username) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "[Hash] Akun \"" << username << "\" tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) hashTable[index] = temp->next;
    else prev->next = temp->next;

    cout << "[Hash] Akun \"" << username << "\" berhasil dihapus.\n";
    delete temp;
}

bool login(string username, string password) {
    NodeAkun* akun = searchAkun(username);
    if (akun != nullptr && akun->password == password) return true;
    return false;
}

int main(void) {
    cout << "=== SISTEM LOGIN MAHASISWA (HASH TABLE) ===\n\n";

    initHashTable();

    insertAkun("fajar", "rahasia123");
    insertAkun("andi", "passandi");
    insertAkun("budi", "passbudi");

    cout << "\n";
    if (login("fajar", "rahasia123")) {
        cout << "[Login] Username \"fajar\" berhasil login.\n";
    } else {
        cout << "[Login] Username/password salah.\n";
    }

    cout << "\n";
    if (login("fajar", "salahpassword")) {
        cout << "[Login] Username \"fajar\" berhasil login.\n";
    } else {
        cout << "[Login] Login gagal untuk \"fajar\" (password salah).\n";
    }

    cout << "\n";
    deleteAkun("andi");

    if (searchAkun("andi") == nullptr) {
        cout << "[Cek] Akun \"andi\" sudah tidak ada di sistem.\n";
    }

    return 0;
}
