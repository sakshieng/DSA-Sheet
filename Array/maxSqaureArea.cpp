// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int>h1;
        unordered_set<int>v1;
        for(int i = 0;i<h.size();i++){
            for(int j = i+1;j<h.size();j++){
                h1.insert(h[j]-h[i]);
            }
        }
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                v1.insert(v[j]-v[i]);
            }
        }
        int side = 0;
        for(auto x : h1){
            if(v1.find(x)!=v1.end()){
                side = max(side, x);
            }
        }
        if(side==0) return -1;
        return (1LL*side*side)%1000000007;
    }
};
