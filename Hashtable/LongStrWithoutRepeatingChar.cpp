#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

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
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};