#include<bits/stdc++.h>
//https://leetcode.com/problems/find-the-winner-of-an-array-game/?envType=daily-question&envId=2023-11-05
using namespace std;
class Solution {
    //tc O(n)
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int mini = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if(winner > arr[i])
                mini++;
            else{
                winner = arr[i];
                mini = 1;
            }
            if(mini == k)
                return winner;
        }
        return arr[0];
    }
};