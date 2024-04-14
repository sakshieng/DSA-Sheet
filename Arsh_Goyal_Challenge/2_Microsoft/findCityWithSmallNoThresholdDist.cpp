// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

//floyd warshall algo
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n+1,vector<int>(n+1,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

        int cityCnt = n,cityNo = -1;//total cities are n
        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adjCity = 0; adjCity < count; adjCity++)
            {
                if(dist[city][adjCity] <= distanceThreshold)
                    count++;
            }
            if(count<=cityCnt)
            {
                cityCnt = count;
                cityNo = city;
            }
        }
        return cityNo;//which city has smallest threshold tyacha no return kra
    }
};