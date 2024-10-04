#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-characters-by-frequency/


    string frequencySort(string s)
    {
        int n = s.size();
        unordered_map<int, int> mp;
        for (auto &i : s)
        {
            mp[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto &it : mp)
        {
            pq.push({it.second, it.first});
        }
        string ans = "";
        pair<int, char> u;
        while (!pq.empty())
        {
            u = pq.top();
            pq.pop();
            for (int i = 0; i < u.first; ++i)
            {
                ans.push_back(u.second);
            }
        }
        return ans;
    }


int main(){
    string k = "aaaabbbkaa";
    string ans = frequencySort(k);
    cout << ans << "\n";
}