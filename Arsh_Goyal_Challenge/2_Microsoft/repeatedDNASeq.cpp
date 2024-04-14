//https://leetcode.com/problems/repeated-dna-sequences/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//every seq of 10 char will be added to hashset result should be stored first in hashset so that they won't get repated & then convert this set to vector 
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for (int i = 0; i < s.length(); i++)
        {
            string substr = s.substr(i,10);
            mp[substr]++;
            if(mp[substr] == 2)
                ans.push_back(substr);
        }
        return ans;
    }
};