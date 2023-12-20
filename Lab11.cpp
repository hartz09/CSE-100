#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

struct Node {
    vector<Edge> edges;
    int key, parent;
    bool inMST;

    Node() : key(INT_MAX), parent(-1), inMST(false) {}
};

void computeMST(vector<Node> &graph, int root) {
    int vertices = graph.size();
    graph[root].key = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
    minHeap.push(make_pair(0, root));

    while (!minHeap.empty()) {
        int current = minHeap.top().second;
        minHeap.pop();

        if (graph[current].inMST) continue;

        graph[current].inMST = true;

        for (Edge &edge : graph[current].edges) {
            int adjacent = edge.to;
            int weight = edge.weight;
            if (!graph[adjacent].inMST && weight < graph[adjacent].key) {
                graph[adjacent].parent = current;
                graph[adjacent].key = weight;
                minHeap.push(make_pair(graph[adjacent].key, adjacent));
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<Node> graph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].edges.emplace_back(v, weight);
        graph[v].edges.emplace_back(u, weight);
    }

    int startingVertex = 0;
    computeMST(graph, startingVertex);

    for (int i = 1; i < numVertices; ++i) {
        cout << graph[i].parent << endl;
    }

    return 0;
}
