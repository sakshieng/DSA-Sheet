#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0;
        while(j < s.size()){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp[s[j]] > 1){
                while(mp[s[j]] > 1){
                    mp[s[i]]--;
                    if(mp[s[j]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};
