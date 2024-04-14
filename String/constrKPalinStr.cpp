#include<bits/stdc++.h>
//https://leetcode.com/problems/construct-k-palindrome-strings/description/
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k || k > s.size()) return 0;
        map<int,int>mp;
        int cnt =0;
        for(auto i:s) mp[i]++;
        for(auto a:mp) if(a.second %2 != 0) cnt++;//no of odd
        return cnt <= k;
    }
};
/*
for str we know for sure single char is always palin so we will try to see in len-1 part can we make a str which in palin in that part 
*/