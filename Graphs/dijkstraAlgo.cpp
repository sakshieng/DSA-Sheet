#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// set implmentation of Dijkstra
using namespace std;
// impemented by set and priority queue
/*make a priority queue(min heap) and store all (dis,node) pair, make a distance array to store all paths weights stor graph in adjacency list
TC->O((N+E)log N)
SC->O(N)
(we can implement this algo in this set<pair<int,int>>s; as we have do have delete option in it)
=>consider all the paths possible between a pair of nodes
1----2----5
|    |    |
|   |     |
4----3----
 1->2=2
 2->5=5
 1->4=1
 3->5=1
 2->3=4
 3->4=3
 Priority queue->
 |  (1,4) |
 |  (5,5) |
 |  (2,2) |
 |  (4,3) |
 |  (7,5) |
 |  (0,1) |
 |________|
  (dis,node)
  from 1 all distances are measured
dis array->

0 0 2 4 1 5<--weights of paths from 1
_ _ _ _ _ _
0 1 2 3 4 5<--indices
even for the dense graph TC in worst case would be O(Elog V)
*/
int main()
{
    int n = 5, m = 6, source = 1;
    //    cin>>n>>m;
    vector<pair<int, int>> g[n + 1]; // adj list for graph 1 base indexing
    //    int a,b,wt;
    //    for(int i=0;i<m;++i)
    //    {
    //     cin>>a>>b>>wt;
    //     g[a].push_back(make_pair(b,wt));
    //     g[b].push_back(make_pair(a,wt));
    //    }
    //    cin>>source;
    g[1].push_back({2, 2});
    g[1].push_back({4, 1});
    g[2].push_back({1, 2});
    g[2].push_back({5, 5});
    g[2].push_back({3, 4});
    g[3].push_back({2, 4});
    g[3].push_back({4, 3});
    g[3].push_back({5, 1});
    g[4].push_back({1, 1});
    g[4].push_back({3, 3});
    g[5].push_back({2, 5});
    g[5].push_back({3, 1});
    //    actual algo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap in pair (dist,node)
    vector<int> distTo(n + 1, INT_MAX);                                                 // array for shortest paths
    distTo[source] = 0;
    pq.push(make_pair(0, source)); //(dist,from)

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (auto it : g[prev]) // iterate on adj list
        {
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout << "The distance from source, " << source << ",are:\n";
    for (int i = 1; i <= n; ++i)
    {
        cout << distTo[i] << " ";
    }
    cout << endl;
    return 0;
}
