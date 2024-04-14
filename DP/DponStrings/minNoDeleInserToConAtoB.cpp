// https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&leftPanelTab=0
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

#include<bits/stdc++.h>
vector<vector<int>>dp;
int helper(string &w1, string &w2, int i, int j) {
        if(i == w1.size() && j == w2.size()) return 0;//means same str
        if(i == w1.size() || j == w2.size()) return max(w1.size() - i, w2.size() - j);//if one of the string is empty we will return char from str which is nonempty
        if(dp[i][j] != 1000) return dp[i][j];  
        if(w1[i] == w2[j]) return helper(w1, w2, i + 1, j + 1);
        return dp[i][j] = 1 + min(helper(w1, w2, i + 1, j), helper(w1, w2, i, j + 1));
}
int canYouMake(string &word1, string &word2){
    dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, 1000));
    return helper(word1, word2, 0, 0);
}
    