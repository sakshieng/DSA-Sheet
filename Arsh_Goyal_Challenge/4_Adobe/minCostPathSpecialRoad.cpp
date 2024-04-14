#include <bits/stdc++.h>
// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/
// sakshi codes here
using namespace std;

// special nodes fkt travel krt jayche
// ith node prynt jaycha distance ha ahe
//from curr node to start of speacail node

class Solution {
    // djkistra single source shortest path
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        int n = sr.size();
        vector<int>dist(n, 1e8);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; ++i){
            // ith node distance to start
            dist[i] = abs(sr[i][0] - start[0]) + abs(sr[i][1] - start[1]) + sr[i][4];//that speical cost
        // ith node priority in the queue
            pq.push({dist[i], i}); 
        } 

        int ans = INT_MAX;

        // while (!pq.empty()) {
        //    auto &[distUntillNow, node] = pq.top(); pq.pop();
        //     ans = min(ans, abs(sr[node][2] - target[0]) + abs(sr[node][3] - target[1]) + distUntillNow);
        //     for(int i = 0; i < n; ++i){
        // // neighbouring nodes vr traverse keley
        //         int d = abs(sr[i][0] - sr[node][2]) + abs(sr[i][1] - sr[node][3]) + sr[i][4];
        //         // relaxation
        //         if(d + distUntillNow < dist[i]){
        //             dist[i] = d +  distUntillNow;
        //             pq.push({dist[i], i});
        //         }
        //     }
        // }

        ans = min(ans, abs(start[0] - target[0]) + abs(start[1] - target[1]));
        return ans;
    }
};
