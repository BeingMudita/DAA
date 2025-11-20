#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

// Comparison function to sort edges by weight
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

// Disjoint Set Union (Union-Find) with path compression
int findParent(int u, vector<int> &parent) {
    if (u == parent[u]) return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Initialize DSU
    vector<int> parent(V + 1), rank(V + 1, 0);
    for (int i = 1; i <= V; i++) parent[i] = i;

    vector<Edge> result; // store MST edges
    int mstWeight = 0;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            unionSets(e.u, e.v, parent, rank);
            result.push_back(e);
            mstWeight += e.w;
        }
    }

    cout << "\nEdges in MST:\n";
    for (auto e : result) {
        cout << e.u << " - " << e.v << " : " << e.w << endl;
    }
    cout << "Total weight of MST = " << mstWeight << endl;

    return 0;
}
