#include<bits/stdc++.h>
//https://leetcode.com/problems/longest-repeating-character-replacement/description/
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // choose any char of str & change it to any other uppercase English char perform it k times    
        //tc O(n) sc O(1)
        if(s.size() == 0) return 0;
        vector <int> arr(128);
        int begin = 0,maxi =0;
        for(int i=0;i<s.size();++i){
            // add a unique character in the current window and get max from it
            maxi = max(maxi,++arr[s[i]]);
            //we are allowed to have at most k replce so if max char freqn+dis(beg,i i.e end)>k that means we have reached to largest sequ
            if(i-begin+1-maxi > k) arr[s[begin++]]--;
        }
        //return sequ we got
        return s.length()-begin;
    }
};