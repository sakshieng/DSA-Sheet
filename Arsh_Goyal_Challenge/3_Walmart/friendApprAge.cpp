#include<bits/stdc++.h>
//https://leetcode.com/problems/friends-of-appropriate-ages/
using namespace std;

class Solution {
public:
    bool canSendRequest(int a,int b){
        return !(b<=(0.5*a+7) or (b>a) or (b>100 and a<100));
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mp;
        for(int &age:ages)
            mp[age]++;
        int res = 0;
        for(auto &a:mp){
            for(auto &b:mp){
                if(canSendRequest(a.first,b.first));
                    res += a.second*(b.second-(a.first == b.first)?1:0);
            }
        }
        return res;
    }
};
/*
y>100 & x<100
means obv y>x
so no use of 3rd case
lower bound or Binary search krycha
2 same val astil tr 1st person je friend krel tech 2nd person friend krel so no need of doing bs on thst
16 ->1
17 ->1
18 ->1
*/