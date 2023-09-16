#include<bits/stdc++.h>
// https://leetcode.com/problems/min-cost-to-connect-all-points/description/?envType=daily-question&envId=2023-09-15
using namespace std;
class Solution {
public:
    int dis(vector<int>&point1,vector<int>&point2)
    {
        return abs(point1[0]-point2[0])+ abs(point1[1]-point2[1]);//simple manhattan dis 
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>visited(n,0);
        vector<int>minCost(n,INT_MAX);
        int curr=0;
        minCost[0]=0;
        int ans=0;
        while(curr >= 0)
        {
            visited[curr] = 1;
            int nextpoint = -1;//curr la kuthe attach krnar
            int mincurr = INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(visited[i] || curr==i)
                {
                    continue;
                }
                minCost[i]=min(dis(points[curr],points[i]),minCost[i]);
                if(minCost[i]<mincurr)
                {
                    mincurr = minCost[i];
                    nextpoint = i;
                }
            }
            if(mincurr==INT_MAX) ans += 0;
            else ans += mincurr;
            curr = nextpoint;
        }
        return ans;
    }
};