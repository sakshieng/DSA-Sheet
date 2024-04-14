// bottom-up tabulation method

#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
//  https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344?leftPanelTab=1

class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // in which ways u have to do and find min then that time we do partition dp
        int dp[N][N];
        for (int i = 1; i < N; ++i)
            dp[i][i] = 0;
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int mini = 1e9;
                for (int k = i; k < j; ++k)
                {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    if (steps < mini)
                        mini = steps;
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
    // memo O(n^3) sc O(n^2)
};
