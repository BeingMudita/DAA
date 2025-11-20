#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int vertex;
    int distance;

    bool operator>(const Node &other) const {
        return distance > other.distance;
    }
};

void dijkstra(int V, vector<pair<int,int>> adj[], int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Min-heap {distance, vertex}
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    minHeap.push({source, 0});

    while (!minHeap.empty()) {
        Node node = minHeap.top();
        minHeap.pop();

        int u = node.vertex;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                minHeap.push({v, dist[v]});
            }
        }
    }

    cout << "Vertex\tDistance from Source (" << source << ")\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Graph edges
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[0].push_back({4, 3});
    adj[2].push_back({1, 2});
    adj[3].push_back({4, 4});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}
