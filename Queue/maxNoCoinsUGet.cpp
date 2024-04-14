#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=daily-question&envId=2023-11-24
class Solution {
public:
//sort piles put it in deque
// each step pop & give it to alice 
//we pop from the back again and take this pile for ourselves
//finally pop from front & give to bob we just need score adn no need to track who is winner
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int>dq;
        for(int i:piles)
            dq.push_back(i);
        int ans = 0;
        while(!dq.empty()){
            dq.pop_back();//alice
            ans += dq.back();//for ourselves
            dq.pop_back();
            dq.pop_front();//to bob
        }
        return ans;
    }
};