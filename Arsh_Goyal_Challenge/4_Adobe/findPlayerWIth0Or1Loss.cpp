// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

//hashmap interesting que
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        //could be solved by sets too 
        map<int,int>mp;//no use of unorderd map as only map is used to store elements by sorted way while other stores in unsorted way
        for (int i = 0; i < matches.size(); i++)
        {
            mp[matches[i][0]]+=0;
            mp[matches[i][1]]++;
        }
        vector<vector<int>>ans(2);//size 2 always
        for(auto &i:mp){
            if(i.second == 0)
                ans[0].push_back(i.first);//freq at 2nd idx 0 means he winner

            if(i.second == 1)//freq of occuring in 2nd idx means at losing side is 1 so he is loser
                ans[1].push_back(i.first);

        }
        return ans;
    }
};