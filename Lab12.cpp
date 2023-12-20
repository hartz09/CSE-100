#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int v, int e) : V(v), E(e) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (const Edge &edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int weight = edge.weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        bool negativeCycle = false;
        for (const Edge &edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) {
            cout << "FALSE" << endl;
        } else {
            cout << "TRUE" << endl;
            for (int i = 0; i < V; ++i) {
                if (dist[i] == INT_MAX) {
                    cout << "INFINITY" << endl;
                } else {
                    cout << dist[i] << endl;
                }
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph graph(V, E);

    int src, dest, weight;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.bellmanFord(0); // Assuming source vertex is 0

    return 0;
}
