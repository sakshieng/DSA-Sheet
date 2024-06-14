// https://leetcode.com/contest/weekly-contest-373/problems/make-lexicographically-smallest-array-by-swapping-elements/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class DSU
{
public:
    vector<int> par, rank;
    DSU(int n)
    {
        par.resize(n), rank.resize(n);
        iota(begin(par), end(par), 0); // to assign successive values of value to every element in a specified range.
    }
    int find(int u)
    {
        return par[u] = (par[u] == u ? u : find(par[u]));
    }
    void merge(int u, int v)
    {
        int x = find(u), y = find(v);
        if (x == y)
            return; // already same no need to merge
        if (rank[x] < rank[y])
            swap(x, y);
        else if (rank[x] == rank[y])
            rank[x]++;
        par[y] = x;
    }
};
class Solution
{
    unordered_map<int, vector<pair<int, int>>> mp;

public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        // make a virtual graph with nums are nodes we care only about the connected components
        // will use DSU to obtain components sort in DSu TC O(n*log n)
        int n = nums.size();
        vector<pair<int, int>> all;
        for (int i = 0; i < n; i++)
        {
            all.push_back({nums[i], i});
        }
        sort(begin(all), end(all), [&](auto &a, auto &b)
             {
            if(a.first != b.first)  return a.first < b.first;
            return a.second < b.second; });
        DSU dsu(n + 1);
        // inserting 0th element
        mp[all[0].second].push_back({all[0].first,all[0].second});
        for (int i = 1;i < n;++i){
            
        }
    }
};