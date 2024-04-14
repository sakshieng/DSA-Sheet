//Josephus Problem
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
class Solution {
public:
//by recursion 
    int solve(int n,int k){
        if(n==1) return 0;
        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return 1 + solve(n,k);//as answer comes after mod so it will come in 0 base idx
    }
};