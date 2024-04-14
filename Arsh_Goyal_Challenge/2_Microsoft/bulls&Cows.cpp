#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>secret_freq;
        unordered_map<char,int>guess_freq;
        //secret chi freqn store krychi
        //bulls count kryche
        int bulls=0;
        for (int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
                bulls++;
            else
                secret_freq[secret[i]]++,guess_freq[guess[i]]++;
        }
        
        int cows = 0;
        //it.second->freqn in guess 
        //1123 ani 0111 2nd idx la bull++ 1 chi freq in secret 1 ali ani 1 chi guess mdhe freq 2 ali tr mg min ghya
        for(auto &it:guess_freq)
            cows += min(it.second,secret_freq[it.first]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};