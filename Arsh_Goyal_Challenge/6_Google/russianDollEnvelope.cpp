#include <bits/stdc++.h>
//https://leetcode.com/problems/russian-doll-envelopes/
using namespace std;


class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])       // width same
            return a[1] > b[1]; // height nusar sort
        return a[0] < b[0];//width chya asending
    }
    
    int lis(vector<int> const& a) {
        int n = a.size();
        const int INF = 1e9;
        vector<int> d(n+1, INF);
        d[0] = -INF;
    
        for (int i = 0; i < n; i++) {
            int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
            if (d[l-1] < a[i] && a[i] < d[l])
                d[l] = a[i];
        }
    
        int ans = 0;
        for (int l = 0; l <= n; l++) {
            if (d[l] < INF)
                ans = l;
        }
        return ans;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(begin(envelopes),end(envelopes),compare);
        vector<int> heights;
        for (const vector<int> &i : envelopes)
            heights.push_back(i[1]);
        return lis(heights);
    }
};