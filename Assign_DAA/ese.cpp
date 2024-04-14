//Write a program to use color interchange method to perform vertex coloring of graph

#include<bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> graph = {
    {0, {1, 2, 4, 5}},
    {1, {0, 2, 3, 5}},
    {2, {0, 1, 3, 4}},
    {3, {1, 2, 4, 5}},
    {4, {0, 2, 3, 5}},
    {5, {0, 1, 3, 4}}
};

vector<string> colors = {"Blue", "Green", "Red", "Grey", "White", "Pink", "Black"};

void color_root(unordered_map<int, vector<int>>& graph, int vertex) {
    graph[vertex].push_back(-1); // -1 indicates uncolored
}

vector<int> reset(int numVertices) {
    vector<int> result(numVertices, -1); // -1 indicates uncolored
    return result;
}

void print_graph(const unordered_map<int, vector<int>>& g) {
    unordered_set<string> c;
    for (const auto& pair : g) {
        cout << pair.first << ": ";
        for (int vertex : pair.second) {
            cout << vertex << " ";
        }
        cout << "(Color: " << colors[pair.second.back()] << ")" << endl;
        c.insert(colors[pair.second.back()]);
    }
    cout << "\nColors needed to perform vertex coloring: ";
    for (const auto& i : c) {
        cout << i << " ";
    }
    cout << "\n\n";
}

bool interchange_colors(unordered_map<int, vector<int>>& graph, int vertex) {
    auto temp = reset(graph.size());
    for (int neighbor : graph[vertex]) {
        if (neighbor != -1 && temp[neighbor] != -1) {
            temp.erase(temp.begin() + neighbor);
        }
    }

    int currentColor = graph[vertex].back();
    int newColor = temp[0];

    if (currentColor != newColor) {
        graph[vertex].back() = newColor;
        return true; // Colors were interchanged
    }

    return false; // No interchange of colors
}

void color_graph(unordered_map<int, vector<int>>& graph) {
    int startVertex = graph.begin()->first;
    color_root(graph, startVertex);

    bool changed;
    do {
        changed = false;

        for (auto& pair : graph) {
            int vertex = pair.first;
            if (interchange_colors(graph, vertex)) {
                changed = true;
            }
        }
    } while (changed);

    print_graph(graph);
}

int main() {
    color_graph(graph);

    return 0;
}
