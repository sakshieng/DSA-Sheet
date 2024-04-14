// https://leetcode.com/problems/bus-routes/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        // we have to store stops and bus cha vector chya idx in hash
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> adj;

        for (int route = 0; route < routes.size(); ++route)
            for (auto &stop : routes[route])
                adj[stop].push_back(route);

        // bfs
        queue<int> q;
        vector<bool> visited(501, 0);
        for (auto &route : adj[source])
        {
            q.push(route);
            visited[route] = 1;
        }
        int busCnt = 1; // source wala bus so cnt 1 ne suru
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {

                int route = q.front();
                q.pop();
                for (auto &stop : routes[route])
                {
                    if (stop == target)
                        return busCnt;
                    // if not target then we have to check at which indices this stop is present
                    for (auto &nextRoute : adj[stop])
                    {
                        if (visited[nextRoute] == 0)
                        {
                            visited[nextRoute] = 1;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCnt++;
        }
        return -1; // target nhi milala
    }
};
//tc m routes maxSTops = k O(m*k^2) 