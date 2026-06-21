/*
Implementasi Algoritma Dijkstra dalam C++

Studi Kasus: Food Delivery
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int main(void) {
    vector<string> loc = {
        "Restoran",
        "A",
        "B",
        "C",
        "D",
        "E",
        "Pelanggan"
    };

    int n = 7;
    vector<pair<int, int>> graph[7];

    auto addEdge = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(0, 3, 7);
    addEdge(1, 2, 3);
    addEdge(1, 5, 6);
    addEdge(2, 3, 3);
    addEdge(2, 4, 2);
    addEdge(2, 5, 3);
    addEdge(3, 4, 4);
    addEdge(4, 6, 3);
    addEdge(5, 6, 4);

    vector<int> dist(n, INF);
    vector<int> par(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0;
    int goal = 6;

    dist[start] = 0;

    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(d > dist[u]) {
            continue;
        }

        for(auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;

    int i;
    for(i = goal; i != -1; i = par[i]) {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    cout << "=== FOOD DELIVERY ===\n\n";
    cout << "Rute Tercepat: \n";

    for(i = 0; i < path.size(); i++) {
        cout << loc[path[i]];

        if(i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\n\n";

    cout << "Total Waktu Ditempuh: " << dist[goal] << " menit\n";

    return 0;
}