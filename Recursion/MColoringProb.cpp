#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, bool graph[101][101], int color[], int n, int col) {//for checking if any adjacent node has same color
        for (int i = 0; i < n; ++i) {
            if (i != node && graph[i][node] == 1 && color[i] == col) return false;
        }
        return true;
    }

    bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
        if (node == N) return true;//colored all nodes

        for (int i = 1; i <= m; ++i) {
            if (isSafe(node, graph, color, N, i)) {
                color[node] = i;
                if (solve(node + 1, color, m, N, graph)) return true;
                color[node] = 0;//we have to erase that color if its not possible to color
            }
        }
        return false;
    }

    

    bool graphColoring(bool graph[101][101], int m, int n) {
        //possible to color
        int color[n] ={0};//none of the nodes colored hence initialize to 0
        if(solve(0,color,m,n,graph)) return 1;
        return 0;
    }
    //TC->O(n^m) b=n nodes m colors SC->O(n)+O(n) as auxilary stack space
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}
