// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>aIdx,bIdx;
        int n = s.length();
        if(a.size() > s.size() or b.size()>s.size())
                return {};
        for(int i=0;i <= n-b.length();++i)
            if(s.substr(i,b.length()) == b)
                bIdx.push_back(i);
        
        vector<int>ans;
        int x = a.length();
        for(int i=0;i<n;++i){
            if(s.substr(i,x) == a)
            {
                for(auto it:bIdx){
                    if(abs(it-i) <= k)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};