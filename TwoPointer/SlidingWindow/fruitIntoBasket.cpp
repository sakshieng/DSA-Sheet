#include<bits/stdc++.h>
//https://leetcode.com/problems/fruit-into-baskets/ 
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 1) return 1;
        // //use pair to store {fruit_type,cnt in basket}
        // pair<int,int>P1={-1,0};
        // pair<int,int>P2={-1,0};
        map<int,int>mp;
        //sliding window
        int left=0,right=0,ans=INT_MIN;
        while(right < fruits.size()){
            while(left<right && mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            while(right<fruits.size() && mp.size() <= 2){
                mp[fruits[right]]++;
                right++;
            }
            if(mp.size() > 2){
                ans = max(ans,right-left-1);
            }else{
                ans = max(ans,right-left);
            }
        }
        return ans;
    }
};