#include<bits/stdc++.h>
//https://leetcode.com/problems/find-unique-binary-string/description/
using namespace std;
//hint is ki we can convert convert str to 10 base integer and then if we want unique str of len-2 then we would return the integer which is not in nums
//store the equivalent integers in hashset
//sometime when converted binary str has len<n then add "0" in beginning
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>unique;
        for(string it:nums)
            unique.insert(stoi(it,0,2));//0-2 means base 10
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            if(unique.find(i) == unique.end()){
                string a = bitset<16>(i).to_string();
                return a.substr(16-n);//means equivalent str of len=n will be returned as answer
            }
        }
        return "";
    }
};