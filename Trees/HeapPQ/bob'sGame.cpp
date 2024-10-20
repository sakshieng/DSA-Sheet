#include<bits/stdc++.h>
//https://practice.geeksforgeeks.org/contest/gfg-weekly-164-rated-contest/problems
using namespace std;

class Solution {
  public:
    vector<int> removeOrder(int n, vector<int> &arr, string &str) {
    
    vector<int> result(n);
    
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    unordered_map<int, int> mp;
    
    for (int num : arr) {
        maxi.push(num);
        mini.push(num);
        mp[num]++;
    }
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            while (mp[mini.top()] == 0) {
                mini.pop();
            }
            int chosen = mini.top();
            result[i] = chosen;
            mp[chosen]--;
            if (mp[chosen] == 0) {
                mini.pop();
            }
        } else {
            while (mp[maxi.top()] == 0) {
                maxi.pop();
            }
            int chosen = maxi.top();
            result[i] = chosen;
            mp[chosen]--;
            if (mp[chosen] == 0) {
                maxi.pop();
            }
        }
    }

    return result;
    }
};