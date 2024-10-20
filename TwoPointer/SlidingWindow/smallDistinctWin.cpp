// https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution{
    public:
    int findSubString(string s)
    {
        unordered_map<char,bool>mp;
        for(char c:s) mp[c] = 1;
        int cnt = mp.size();
        unordered_map<char, int> windowFreq;  
        int left = 0, mini = INT_MAX;
        int matchedCount = 0;  

        for (int right = 0; right < s.size(); right++)
        {
            char rightChar = s[right];
            windowFreq[rightChar]++;
            
            if(windowFreq[rightChar]++ == 1)
                matchedCount++;
            
            while (matchedCount == cnt)//cnt is required cnt
            {
                mini = min(mini,right-left+1);
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if(windowFreq[leftChar] == 0)
                    matchedCount--;
                left++;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};

