#include <bits/stdc++.h>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string prodi;
    int semester;
    string password;
};

struct NodeHash {
    Mahasiswa data;
    NodeHash* next;
};

const int HASH_SIZE = 10;
NodeHash* hashTable[HASH_SIZE];

void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

int hashFunction(string nim) {
    int sum = 0;
    for (char c : nim) sum += c;
    return sum % HASH_SIZE;
}

void registerAkun(string nim, string nama, string prodi, int semester, string password) {
    int index = hashFunction(nim);

    Mahasiswa mhs;
    mhs.nim = nim;
    mhs.nama = nama;
    mhs.prodi = prodi;
    mhs.semester = semester;
    mhs.password = password;

    NodeHash* newNode = new NodeHash{mhs, nullptr};

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        NodeHash* temp = hashTable[index];
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    cout << "[Sistem] Akun " << nama << " (" << nim << ") berhasil didaftarkan.\n";
}

Mahasiswa* cariAkun(string nim) {
    int index = hashFunction(nim);
    NodeHash* temp = hashTable[index];
    while (temp != nullptr) {
        if (temp->data.nim == nim) return &(temp->data);
        temp = temp->next;
    }
    return nullptr;
}

bool login(string nim, string password) {
    Mahasiswa* mhs = cariAkun(nim);
    if (mhs != nullptr && mhs->password == password) return true;
    return false;
}

struct NodeRiwayat {
    string aktivitas;
    NodeRiwayat* next;
};

NodeRiwayat* headRiwayat = nullptr;

void tambahAktivitas(string aktivitas) {
    NodeRiwayat* newNode = new NodeRiwayat{aktivitas, nullptr};

    if (headRiwayat == nullptr) {
        headRiwayat = newNode;
    } else {
        NodeRiwayat* temp = headRiwayat;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
}

void tampilkanRiwayat() {
    cout << "\n=== Riwayat Aktivitas ===\n";
    NodeRiwayat* temp = headRiwayat;
    while (temp != nullptr) {
        cout << " -> " << temp->aktivitas << "\n";
        temp = temp->next;
    }
}

struct NodeAntrian {
    string nama;
    NodeAntrian* next;
};

NodeAntrian* frontAntrian = nullptr;
NodeAntrian* rearAntrian = nullptr;

void enqueueKonsultasi(string nama) {
    NodeAntrian* newNode = new NodeAntrian{nama, nullptr};

    if (rearAntrian == nullptr) {
        frontAntrian = rearAntrian = newNode;
    } else {
        rearAntrian->next = newNode;
        rearAntrian = newNode;
    }

    cout << "[Antrian] " << nama << " masuk antrian konsultasi.\n";
}

void dequeueKonsultasi() {
    if (frontAntrian == nullptr) {
        cout << "[Antrian] Tidak ada antrian saat ini.\n";
        return;
    }

    NodeAntrian* temp = frontAntrian;
    cout << "[Antrian] Sedang melayani: " << frontAntrian->nama << "\n";

    frontAntrian = frontAntrian->next;
    if (frontAntrian == nullptr) rearAntrian = nullptr;

    delete temp;
}

struct NodeTree {
    string jabatan;
    vector<NodeTree*> children;
};

NodeTree* buatNodeTree(string jabatan) {
    NodeTree* newNode = new NodeTree();
    newNode->jabatan = jabatan;
    return newNode;
}

NodeTree* tambahAnak(NodeTree* parent, string jabatanAnak) {
    NodeTree* newNode = buatNodeTree(jabatanAnak);
    parent->children.push_back(newNode);
    return newNode;
}

void tampilkanTree(NodeTree* node, int level = 0) {
    if (node == nullptr) return;

    for (int i = 0; i < level; i++) cout << "   ";
    cout << "|-- " << node->jabatan << "\n";

    for (NodeTree* child : node->children) {
        tampilkanTree(child, level + 1);
    }
}

const int MAX_GEDUNG = 100;
vector<pair<int, int>> adjGraph[MAX_GEDUNG];
string namaGedung[MAX_GEDUNG];
int jumlahGedung = 0;

void setNamaGedung(int id, string nama) {
    namaGedung[id] = nama;
    if (id + 1 > jumlahGedung) jumlahGedung = id + 1;
}

void tambahJalan(int u, int v, int jarak) {
    adjGraph[u].push_back({v, jarak});
    adjGraph[v].push_back({u, jarak});
}

void ruteTercepatDijkstra(int start, int dest) {
    vector<int> dist(jumlahGedung, 1e9);
    vector<int> parent(jumlahGedung, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adjGraph[u]) {
            int v = edge.first;
            int bobot = edge.second;

            if (dist[u] + bobot < dist[v]) {
                dist[v] = dist[u] + bobot;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\n[Navigasi] Rute Tercepat: " << namaGedung[start] << " ke " << namaGedung[dest] << "\nJalur: ";

    vector<int> path;
    for (int curr = dest; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }

    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << namaGedung[path[i]] << (i == 0 ? "" : " -> ");
    }

    cout << "\nTotal Jarak: " << dist[dest] << " meter\n";
}

struct NodeKRS {
    string matkul;
    NodeKRS* next;
};

NodeKRS* topKRS = nullptr;

void pushKRS(string matkul) {
    NodeKRS* newNode = new NodeKRS{matkul, topKRS};
    topKRS = newNode;
    cout << "[KRS] Ditambahkan: " << matkul << "\n";
}

void popUndoKRS() {
    if (topKRS == nullptr) {
        cout << "[KRS] Riwayat kosong, tidak ada yang bisa di-undo\n";
        return;
    }

    NodeKRS* temp = topKRS;
    cout << "[KRS] Dibatalkan (Undo): " << topKRS->matkul << "\n";

    topKRS = topKRS->next;
    delete temp;
}

struct Layanan {
    string nama;
    int prioritas;

    bool operator<(const Layanan& other) const {
        return prioritas < other.prioritas;
    }
};

priority_queue<Layanan> antrianLayanan;

void tambahLayanan(string nama, int prioritas) {
    Layanan l;
    l.nama = nama;
    l.prioritas = prioritas;

    antrianLayanan.push(l);
    cout << "[Layanan] " << nama << " masuk dengan level prioritas " << prioritas << "\n";
}

void layaniSelanjutnya() {
    if (antrianLayanan.empty()) {
        cout << "[Layanan] Tidak ada layanan dalam antrian.\n";
        return;
    }

    Layanan l = antrianLayanan.top();
    antrianLayanan.pop();

    cout << "[Layanan] Melayani: " << l.nama << " (Prioritas " << l.prioritas << ")\n";
}

int main(void) {
    cout << "=========================================\n";
    cout << "      SMART CAMPUS NAVIGATION SYSTEM     \n";
    cout << "=========================================\n\n";

    initHashTable();
    registerAkun("5025201001", "Andi", "Informatika", 5, "pass123");

    if (login("5025201001", "pass123")) {
        cout << "[Sistem] Login berhasil!\n\n";
    }

    tambahAktivitas("Login ke sistem");
    tambahAktivitas("Membuka menu KRS");

    pushKRS("Struktur Data");
    pushKRS("Basis Data");
    tambahAktivitas("Menambah matkul Basis Data");

    popUndoKRS();
    tambahAktivitas("Undo matkul terakhir");

    cout << "\n";
    enqueueKonsultasi("Andi");
    enqueueKonsultasi("Budi");
    dequeueKonsultasi();

    cout << "\n";
    tambahLayanan("Citra (Mhs Biasa)", 1);
    tambahLayanan("Budi (Beasiswa)", 2);
    tambahLayanan("Andi (Tingkat Akhir)", 3);

    layaniSelanjutnya();
    layaniSelanjutnya();

    cout << "\n=== Struktur Organisasi ===\n";
    NodeTree* rootOrg = buatNodeTree("Rektor");
    NodeTree* wrAkademik = tambahAnak(rootOrg, "Wakil Rektor Akademik");
    tambahAnak(rootOrg, "Wakil Rektor Kemahasiswaan");
    tambahAnak(wrAkademik, "Fakultas Teknik");
    tambahAnak(wrAkademik, "Fakultas Ekonomi");

    tampilkanTree(rootOrg);

    setNamaGedung(0, "Gerbang Utama");
    setNamaGedung(1, "Fakultas Teknik");
    setNamaGedung(2, "Perpustakaan");
    setNamaGedung(3, "Gedung Rektorat");

    tambahJalan(0, 1, 200);
    tambahJalan(1, 2, 100);
    tambahJalan(0, 2, 400);
    tambahJalan(2, 3, 150);

    ruteTercepatDijkstra(0, 3);
    tambahAktivitas("Mencari navigasi rute ke Rektorat");

    tampilkanRiwayat();

    return 0;
}
