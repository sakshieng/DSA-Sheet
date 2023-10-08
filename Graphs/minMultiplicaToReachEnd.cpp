//for implementing dijstktra we will use min heap and dist array
//no of nodes are from 0 to 9999 the steps are increasing by +1 so queue will store in increasing order 
//dijkistra
// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int MAX = 100005;
        int mod = 100000;
        vector<int> dist(MAX, INT_MAX); 
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == end) return dist[curr]; 
            
            for (int num : arr) {
                int next = (1LL * curr * num) % mod; 
                
                if (dist[next] == INT_MAX) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return -1; 
    }
};

