// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1
// https://leetcode.com/problems/frog-jump/description/
//leetcode que is different check it out
#include <bits/stdc++.h>
using namespace std;
// in this problem we have used concept of memiozation
int f(int ind, vector<int> &heights, vector<int> &dp)
//     f(--,--,intialized vector by call by reference)
{
    //     as n-1 to 0 jump hai top to bootom we have written base index
    if (ind == 0)
        return 0;
    if (dp[ind] + 1 != 0)
        return dp[ind];
    // left recursion call
    int left = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

    //         as will not always happen for ind
    //         jump to 2nd stair
    int right = INT_MAX;
    if (ind > 1)
        right = f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    //   as we need minimum energy
    return dp[ind] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    //     dp(max size,intialized with -1)
    vector<int> dp(n + 1, -1);
    return f(n - 1, heights, dp);
}
//     all possible ways--> recursion
//     count all ways -->best way select
//     here greedy soln will not work in some cases it will missed a way
//     1.index 2.do all stuff on that index 3.take the min
//     we have to find min energy required to reach (n-1)th from 0 index
//     as there is overlapping of some values hence use memorization
//     at 1st index there is no right recursion
//     recurrance-->DP
//     TC -->O(n)
//     recursion stack & array stack-->O(n)


/*
below is simple recursive soln so in final code we have used DP if we run this then time limit gets exceeded
#include<bits/stdc++.h>
int f(int ind,vector<int> &heights)
{
//     as n-1 to 0 jump hai top to bootom we have written base index
    if(ind==0) return 0;
// left recursion call
    int left=f(ind-1,heights)+abs(heights[ind]-heights[ind-1]);

//         as will not always happen for ind
//         jump to 2nd stair
        int right=INT_MAX;
    if(ind>1) right=f(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
//   as we need minimum energy
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
}

*/
