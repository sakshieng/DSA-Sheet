
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        //we are not allowed to go in hori and vertical
        // in dijkistra we need priority queue as the distance is moody there it can be 5 10 anything and at that time we have to store minmum of them in order
        // but in this case distance is increasing just by 1 no need to take min dist so we are just using queue here which will reduce TC by log n
        // queue int and with pair of coodinates

        // 1 edge case if the source is only the destination
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
        queue<pair<int, pair<int, int>>> q;
        // 2d dist array
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            // array are created such that each index represents each adjacent node that a cell may have in a direction
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; ++i)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // checking validity of cell and update if dis is shorte
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol])
                {
                    dist[newRow][newCol] = 1 + dis;

                    // if desti arrived
                    if (newRow == destination.first &&
                        newCol == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};

int main()
{

    
    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
    
}
