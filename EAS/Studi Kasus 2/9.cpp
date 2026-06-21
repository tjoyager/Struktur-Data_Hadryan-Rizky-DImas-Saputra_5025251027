#include <bits/stdc++.h>
using namespace std;

struct Produk {
    string nama;
    int terjual;
};

vector<Produk> heap;

void tukar(int i, int j) {
    Produk temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].terjual > heap[parent].terjual) {
            tukar(index, parent);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int index) {
    int n = heap.size();

    while (true) {
        int kiri = 2 * index + 1;
        int kanan = 2 * index + 2;
        int terbesar = index;

        if (kiri < n && heap[kiri].terjual > heap[terbesar].terjual) {
            terbesar = kiri;
        }
        if (kanan < n && heap[kanan].terjual > heap[terbesar].terjual) {
            terbesar = kanan;
        }

        if (terbesar == index) break;

        tukar(index, terbesar);
        index = terbesar;
    }
}

void insertProduk(string nama, int terjual) {
    heap.push_back({nama, terjual});
    heapifyUp(heap.size() - 1);
    cout << "[Heap] Menambahkan produk \"" << nama << "\" (terjual: " << terjual << ")\n";
}

void updatePenjualan(string nama, int terjualBaru) {
    for (size_t i = 0; i < heap.size(); i++) {
        if (heap[i].nama == nama) {
            heap[i].terjual = terjualBaru;
            heapifyUp(i);
            heapifyDown(i);
            cout << "[Heap] Update penjualan \"" << nama << "\" menjadi " << terjualBaru << "\n";
            return;
        }
    }
    cout << "[Heap] Produk \"" << nama << "\" tidak ditemukan.\n";
}

void produkTerlaris() {
    if (heap.empty()) {
        cout << "[Heap] Belum ada data produk.\n";
        return;
    }
    cout << "[Heap] Produk terlaris saat ini: " << heap[0].nama << " (terjual: " << heap[0].terjual << ")\n";
}

void hapusProdukTerlaris() {
    if (heap.empty()) {
        cout << "[Heap] Heap kosong.\n";
        return;
    }

    Produk teratas = heap[0];
    cout << "[Heap] Menghapus produk terlaris: " << teratas.nama << "\n";

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    if (!heap.empty()) heapifyDown(0);
}

int main(void) {
    cout << "=== SISTEM RANKING E-COMMERCE (MAX HEAP) ===\n\n";

    insertProduk("Sepatu Lari", 500);
    insertProduk("Tas Ransel", 800);
    insertProduk("Jaket Hoodie", 400);
    insertProduk("Kaos Polos", 1000);
    insertProduk("Topi", 600);

    cout << "\n";
    produkTerlaris();

    cout << "\n";
    updatePenjualan("Sepatu Lari", 1500);
    produkTerlaris();

    cout << "\n";
    hapusProdukTerlaris();
    produkTerlaris();

    return 0;
}
