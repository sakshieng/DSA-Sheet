// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/
//leetcode 377 contest 3rd question
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


#define ll long long
class Solution {
public:
//Floyd Warshall's algo to precompute all results
//TC O(n) SC O(1)
    const ll inf = 1e18;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>dist(26,vector<ll>(26,inf));
        int n = original.size();

        for(int i=0;i<26;++i)//set transformation cost of each char to 0
            dist[i][i] = 0;

        for (int i = 0; i < n; i++)
            dist[original[i]- 'a'][changed[i]-'a'] = min(dist[original[i]- 'a'][changed[i]-'a'],1LL*cost[i]);

        //to find minimum cost
        for(int k=0;k < 26;++k)
            for(int i=0;i < 26;++i)
                for(int j=0;j < 26;++j)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

        ll ans = 0;
        for (int i = 0; i < source.length(); i++)
        {
            ans += dist[source[i]-'a'][target[i]-'a'];
            if(ans >= inf)
                return -1;
        }
        return ans;
    }
    
};