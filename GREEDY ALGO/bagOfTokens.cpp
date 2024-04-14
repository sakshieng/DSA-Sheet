#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// /https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04
class Solution {
public:
//buy token with small val sell token with larger val
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int l = 0,r = n-1;
        int score = 0;
        while (l <= r)
        {
            if(tokens[l] <= power){
                power -= tokens[l];
                l++;
                score++;
            }
            else
                if(score > 0){
                    power += tokens[r];
                    r--;
                    score--;
                }
                else
                    break;
        }
        return score;
    }
};