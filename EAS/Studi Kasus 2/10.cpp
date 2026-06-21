#include <bits/stdc++.h>
using namespace std;

struct NodeUser {
    string username;
    string password;
    NodeUser* next;
};

const int HASH_SIZE = 10;
NodeUser* hashTable[HASH_SIZE];

void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) hashTable[i] = nullptr;
}

int hashFunction(string username) {
    int sum = 0;
    for (char c : username) sum += c;
    return sum % HASH_SIZE;
}

void registerUser(string username, string password) {
    int index = hashFunction(username);
    NodeUser* newNode = new NodeUser{username, password, nullptr};

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        NodeUser* temp = hashTable[index];
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    cout << "[User] Akun \"" << username << "\" berhasil didaftarkan.\n";
}

bool loginUser(string username, string password) {
    int index = hashFunction(username);
    NodeUser* temp = hashTable[index];

    while (temp != nullptr) {
        if (temp->username == username && temp->password == password) return true;
        temp = temp->next;
    }
    return false;
}

struct NodeRiwayat {
    string pesanan;
    NodeRiwayat* next;
};

NodeRiwayat* headRiwayat = nullptr;

void tambahRiwayat(string pesanan) {
    NodeRiwayat* newNode = new NodeRiwayat{pesanan, nullptr};

    if (headRiwayat == nullptr) {
        headRiwayat = newNode;
    } else {
        NodeRiwayat* temp = headRiwayat;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
}

void tampilkanRiwayat() {
    cout << "\n=== Riwayat Pesanan ===\n";
    NodeRiwayat* temp = headRiwayat;
    while (temp != nullptr) {
        cout << " -> " << temp->pesanan << "\n";
        temp = temp->next;
    }
}

struct NodePesanan {
    string namaPesanan;
    NodePesanan* next;
};

NodePesanan* frontPesanan = nullptr;
NodePesanan* rearPesanan = nullptr;

void enqueuePesanan(string namaPesanan) {
    NodePesanan* newNode = new NodePesanan{namaPesanan, nullptr};

    if (rearPesanan == nullptr) {
        frontPesanan = rearPesanan = newNode;
    } else {
        rearPesanan->next = newNode;
        rearPesanan = newNode;
    }

    cout << "[Pesanan Masuk] " << namaPesanan << " ditambahkan ke antrian dapur.\n";
}

void prosesPesanan() {
    if (frontPesanan == nullptr) {
        cout << "[Pesanan] Tidak ada pesanan dalam antrian.\n";
        return;
    }

    NodePesanan* temp = frontPesanan;
    cout << "[Dapur] Memproses pesanan: " << frontPesanan->namaPesanan << "\n";
    tambahRiwayat(frontPesanan->namaPesanan);

    frontPesanan = frontPesanan->next;
    if (frontPesanan == nullptr) rearPesanan = nullptr;

    delete temp;
}

struct NodeMenu {
    string nama;
    vector<NodeMenu*> children;
};

NodeMenu* buatNodeMenu(string nama) {
    NodeMenu* newNode = new NodeMenu();
    newNode->nama = nama;
    return newNode;
}

NodeMenu* tambahMenu(NodeMenu* parent, string nama) {
    NodeMenu* newNode = buatNodeMenu(nama);
    parent->children.push_back(newNode);
    return newNode;
}

void tampilkanMenu(NodeMenu* node, int level = 0) {
    if (node == nullptr) return;

    for (int i = 0; i < level; i++) cout << "   ";
    cout << "|-- " << node->nama << "\n";

    for (NodeMenu* child : node->children) {
        tampilkanMenu(child, level + 1);
    }
}

const int MAX_LOKASI = 100;
vector<pair<int, int>> adjList[MAX_LOKASI];
string namaLokasi[MAX_LOKASI];
int jumlahLokasi = 0;

void setNamaLokasi(int id, string nama) {
    namaLokasi[id] = nama;
    if (id + 1 > jumlahLokasi) jumlahLokasi = id + 1;
}

void tambahJalan(int u, int v, int jarak) {
    adjList[u].push_back({v, jarak});
    adjList[v].push_back({u, jarak});
}

void navigasiTercepat(int start, int dest) {
    vector<int> dist(jumlahLokasi, 1e9);
    vector<int> parent(jumlahLokasi, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adjList[u]) {
            int v = edge.first;
            int bobot = edge.second;

            if (dist[u] + bobot < dist[v]) {
                dist[v] = dist[u] + bobot;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "[Navigasi] Rute driver: " << namaLokasi[start] << " -> " << namaLokasi[dest] << "\nJalur: ";

    vector<int> path;
    for (int curr = dest; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }

    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << namaLokasi[path[i]] << (i == 0 ? "" : " -> ");
    }

    cout << "\nJarak: " << dist[dest] << " km\n";
}

struct NodeUndo {
    string itemPesanan;
    NodeUndo* next;
};

NodeUndo* topUndo = nullptr;

void pushItemPesanan(string item) {
    NodeUndo* newNode = new NodeUndo{item, topUndo};
    topUndo = newNode;
    cout << "[Keranjang] Menambahkan: " << item << "\n";
}

void undoPesanan() {
    if (topUndo == nullptr) {
        cout << "[Keranjang] Tidak ada item untuk dibatalkan.\n";
        return;
    }

    NodeUndo* temp = topUndo;
    cout << "[Keranjang] Dibatalkan: " << topUndo->itemPesanan << "\n";

    topUndo = topUndo->next;
    delete temp;
}

struct Driver {
    string nama;
    int prioritas;

    bool operator<(const Driver& other) const {
        return prioritas < other.prioritas;
    }
};

priority_queue<Driver> antrianDriver;

void tambahDriver(string nama, int prioritas) {
    antrianDriver.push({nama, prioritas});
    cout << "[Driver] " << nama << " siap dengan prioritas " << prioritas << "\n";
}

void pilihDriver() {
    if (antrianDriver.empty()) {
        cout << "[Driver] Tidak ada driver yang tersedia.\n";
        return;
    }

    Driver d = antrianDriver.top();
    antrianDriver.pop();

    cout << "[Driver] Memilih driver: " << d.nama << " (Prioritas " << d.prioritas << ")\n";
}

int main(void) {
    cout << "=========================================\n";
    cout << "      APLIKASI FOOD DELIVERY (GOFOOD)     \n";
    cout << "=========================================\n\n";

    initHashTable();
    registerUser("rizky", "pass123");

    if (loginUser("rizky", "pass123")) {
        cout << "[Sistem] Login berhasil!\n\n";
    }

    cout << "=== Menu Restoran ===\n";
    NodeMenu* rootMenu = buatNodeMenu("Restoran Sederhana");
    NodeMenu* makanan = tambahMenu(rootMenu, "Makanan");
    tambahMenu(makanan, "Nasi Goreng");
    tambahMenu(makanan, "Mie Ayam");
    NodeMenu* minuman = tambahMenu(rootMenu, "Minuman");
    tambahMenu(minuman, "Es Teh");
    tambahMenu(minuman, "Jus Alpukat");
    tampilkanMenu(rootMenu);

    cout << "\n=== Keranjang Belanja ===\n";
    pushItemPesanan("Nasi Goreng");
    pushItemPesanan("Es Teh");
    pushItemPesanan("Mie Ayam");
    undoPesanan();

    cout << "\n=== Antrian Pesanan ===\n";
    enqueuePesanan("Nasi Goreng - Rizky");
    enqueuePesanan("Es Teh - Rizky");
    prosesPesanan();
    prosesPesanan();

    cout << "\n=== Pemilihan Driver ===\n";
    tambahDriver("Driver A (Rating 4.5)", 2);
    tambahDriver("Driver B (Rating 4.9)", 3);
    tambahDriver("Driver C (Rating 4.0)", 1);
    pilihDriver();

    cout << "\n=== Navigasi Pengiriman ===\n";
    setNamaLokasi(0, "Restoran");
    setNamaLokasi(1, "Persimpangan A");
    setNamaLokasi(2, "Persimpangan B");
    setNamaLokasi(3, "Rumah Pelanggan");

    tambahJalan(0, 1, 2);
    tambahJalan(1, 3, 5);
    tambahJalan(0, 2, 4);
    tambahJalan(2, 3, 2);

    navigasiTercepat(0, 3);

    tampilkanRiwayat();

    return 0;
}
