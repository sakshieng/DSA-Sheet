#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bool isSafe(int v, int c, vector<int>& color) {
        for (int i = 0; i < V; ++i) {
            if (adj[v][i] && c == color[i]) {
                return false;
            }
        }
        return true;
    }

    bool graphColoringUtil(int m, vector<int>& color, int v) {
        if (v == V) {
            return true;
        }

        for (int c = 1; c <= m; ++c) {
            if (isSafe(v, c, color)) {
                color[v] = c;

                if (graphColoringUtil(m, color, v + 1)) {
                    return true;
                }

                color[v] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int m) {
        vector<int> color(V, 0);

        if (!graphColoringUtil(m, color, 0)) {
            cout << "Graph is not " << m << "-colorable." << endl;
            return false;
        }

        cout << "Graph is " << m << "-colorable. Vertex colors are:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": Color " << color[i] << endl;
        }

        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    int k = 3; 

    g.graphColoring(k);

    return 0;
}