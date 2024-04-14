#include<bits/stdc++.h>
//https://leetcode.com/problems/network-delay-time/
//refer to https://leetcode.com/problems/cheapest-flights-within-k-stops/description/ this as well
//could be solved by Dijkistra Algo as well
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0; 
        for (int i = 1; i <= n; i++) {
            vector<int> temp(dis);
            for (auto &x : times) {
                if (dis[x[0]] != INT_MAX) {
                    temp[x[1]] = min(temp[x[1]], dis[x[0]] + x[2]);
                }
            }
            dis = temp;
        }
        //for all the components
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) {
                return -1;
            }
        }
        
        return *max_element(dis.begin() + 1, dis.end()); 
    }
};
