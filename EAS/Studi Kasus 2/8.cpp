#include <bits/stdc++.h>
using namespace std;

struct Pasien {
    string nama;
    int prioritas;
};

struct BandingkanPasien {
    bool operator()(const Pasien& a, const Pasien& b) {
        return a.prioritas > b.prioritas;
    }
};

priority_queue<Pasien, vector<Pasien>, BandingkanPasien> antrianIGD;

void tambahPasien(string nama, int prioritas) {
    antrianIGD.push({nama, prioritas});
    cout << "[IGD] " << nama << " masuk dengan prioritas " << prioritas << " (" << (prioritas == 1 ? "Kritis" : prioritas == 2 ? "Sedang" : "Ringan") << ")\n";
}

void layaniPasien() {
    if (antrianIGD.empty()) {
        cout << "[IGD] Tidak ada pasien dalam antrian.\n";
        return;
    }

    Pasien p = antrianIGD.top();
    antrianIGD.pop();

    cout << "[IGD] Memanggil pasien: " << p.nama << " (Prioritas " << p.prioritas << ")\n";
}

int main(void) {
    cout << "=== SISTEM IGD RUMAH SAKIT (PRIORITY QUEUE) ===\n\n";

    tambahPasien("Pasien A", 3);
    tambahPasien("Pasien B", 1);
    tambahPasien("Pasien C", 2);

    cout << "\nUrutan pelayanan:\n";
    while (!antrianIGD.empty()) {
        layaniPasien();
    }

    cout << "\n";
    layaniPasien();

    return 0;
}
