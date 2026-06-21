#include <bits/stdc++.h>
using namespace std;

const int MAX_LOKASI = 100;
vector<pair<int, int>> adjList[MAX_LOKASI];
string namaLokasi[MAX_LOKASI];
int jumlahLokasi = 0;

void setNamaLokasi(int id, string nama) {
    namaLokasi[id] = nama;
    if (id + 1 > jumlahLokasi) jumlahLokasi = id + 1;
}

void tambahJalan(int u, int v, int bobot) {
    adjList[u].push_back({v, bobot});
    adjList[v].push_back({u, bobot});
}

void carirutetercepat(int start, int dest) {
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

    if (dist[dest] >= 1e9) {
        cout << "[Maps] Tidak ada rute dari " << namaLokasi[start] << " ke " << namaLokasi[dest] << "\n";
        return;
    }

    cout << "[Maps] Rute tercepat: " << namaLokasi[start] << " -> " << namaLokasi[dest] << "\nJalur: ";

    vector<int> path;
    for (int curr = dest; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }

    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << namaLokasi[path[i]] << (i == 0 ? "" : " -> ");
    }

    cout << "\nJarak minimum: " << dist[dest] << " km\n";
}

int main(void) {
    cout << "=== APLIKASI GOOGLE MAPS (GRAPH + DIJKSTRA) ===\n\n";

    setNamaLokasi(0, "A");
    setNamaLokasi(1, "B");
    setNamaLokasi(2, "C");
    setNamaLokasi(3, "D");

    tambahJalan(0, 1, 5);
    tambahJalan(0, 2, 2);
    tambahJalan(0, 3, 9);
    tambahJalan(1, 3, 3);
    tambahJalan(2, 3, 4);

    carirutetercepat(0, 3);

    return 0;
}
