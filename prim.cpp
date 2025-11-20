#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Adjacency list: (neighbor, weight)
    vector<pair<int,int>> adj[V+1];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    vector<int> key(V+1, INF);   // weight of edge to include vertex
    vector<bool> inMST(V+1, false);
    vector<int> parent(V+1, -1); // store MST edges

    // Min-heap {weight, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int start = 1; // start from vertex 1
    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // already included
        inMST[u] = true;

        // check neighbors
        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "\nEdges in MST:\n";
    for (int v = 2; v <= V; v++) {  // from 2..V (since 1 is root)
        cout << parent[v] << " - " << v << " : " << key[v] << endl;
        totalWeight += key[v];
    }
    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}
