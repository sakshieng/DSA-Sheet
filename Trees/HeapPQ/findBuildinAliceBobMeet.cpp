#include<bits/stdc++.h>
//https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/
//tc O(q*log q) sc O(n+q)
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int totalQueries = queries.size();
        //to store queries 
        vector<int>ans(totalQueries,-1);
        unordered_map<int,vector<pair<int,int>>>mp;//max query idx<max height,query no>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap

        //answer to basic queries 1st then create map
        for (int q = 0; q < totalQueries; q++)
        {
            int i = queries[i][0];
            int j = queries[i][1];

            if(i<j && heights[i]<heights[j])
                ans[q] = j;
            else if(i>j && heights[i]>heights[j])
                    ans[q] = i;
            else if(i == j)
                    ans[q] = i;
            else
                mp[max(i,j)].push_back({max(heights[i],heights[j]),q});//key of map would be max idx of both as right side la ans ansar
        }
        
        //use pq to handle remaing queries
        for(int i=0;i<n;++i){
            while (!pq.empty() && pq.top().first < heights[i])//check with queries can be answered at idx i
            {
                ans[pq.top().second] = i;
                pq.pop();
            }
            for(auto &it:mp[i])
                pq.push(it);//push queries with max idx as i in min heap
        }
        return ans;
    }
};