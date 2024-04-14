#include<bits/stdc++.h>
//https://leetcode.com/problems/constrained-subsequence-sum/description/

/*
HARD -> 2 steps

1st step was bruteforce dp !! O(n*k)
2nd find maximum of last K elements in logn / O(1)
MEDIUM !! -> HARD !!!


memo(int i, vector<int>& v,k){
    if(i == v.size()) return 0;
    long ans = INT_MIN;
    for(int j = i+1; j <= i+k; ++j){
        ans = max(ans, v[j] + memo(j,v,k));
    }
    return ans;
}
----------------------------------
int dp[n+1] : 
dp[i]] -> max sum of subseq such that last element is i
vector<int>dp(n+1,INT_MIN);
dp[0] = 0; !! if I select 0 elements, sum I get is 0
int ans = INT_MIN;
for(int i = 1; i <= n; ++i){
    for(int j = max(i-k,0); j < i; ++j){
        dp[i] = max(dp[i], dp[j]);
    }
    dp[i] += v[i];
    ans = max(ans, dp[i]);
}
cout << ans << "\n";

return dp[n];
---------------------------------------
long long n = nums.size();
  vector<long long>dp(n+1, INT_MIN);
  long long ans = INT_MIN;
  dp[0] = 0;
  for(int i = 1; i <= n; ++i){
      for(int j = max(i-k,0); j < i; ++j){
          dp[i] = max(dp[i], dp[j]);
      }
      dp[i] += nums[i-1];
      dp[i] = max(dp[i], (long long)nums[i-1]);
      ans = max(ans, dp[i]);
  }
  O(n*k) -> O(n); !!
  return ans;

k = 2
1 3 5 100000


dp[i] => maximum subsq sum till i
dp[i] = sumation(dp[i-1], dp[i-k]);


------------------------------------------------------1
5
10 -2 -10 -5 20
2

dp[1] -> dp[0] -> 0!!
dp[1] = 0 + 10 = 10
dp[2] = max(dp[1], dp[0])  +v[2];
dp[2] = 10 + -2 = 8
dp[2] = 8
dp[3] = max(dp[1], dp[2]) + v[3];
     = 10 + -10
 dp[3] = 0
 dp[4] = max(dp[2], dp[3]) + v[4];
 = 8 + -5
 dp[4] = 3
 dp[5] = max(dp[4], dp[3]) + v[5];
      = max(0,3) + 20
       = 3 + 20 = 23

[10,8,0,3,23]


dp[i] = max(dp[i-1],dp[i-2], dp[i-3]..... dp[i-k]) + v[i] >>




---------------------------------------------------------------
SLIDING WINDOW XXXXX

Prioriry Queue

pq<value, index>
5 3 1 4 2
^
for(int i = 0; i < n; ++i){
    while(!pq.empty() && i - pq.top.second > k) pq.pop();
    cout << pq.top().first << " ";
    pq.push({nums[i],i});

}
for(int i = 1; i <= n; ++i){
    for(int j = max(i-k,0); j < i; ++j){
        dp[i] = max(dp[i], dp[j]);
    }
    dp[i] += nums[i-1];
    dp[i] = max(dp[i], (long long)nums[i-1]);
    ans = max(ans, dp[i]);
}
priorirty_queue<value,index>pq;
--------------------------------------------
for(int i = 1; i <= n; ++i){
    while(!pq.empty() && i - pq.top().second > k) pq.pop();
    dp[i] = pq.top().first;
    dp[i] += nums[i-1];
    dp[i] = max(dp[i], (long long)nums[i-1]);
    ans = max(ans, dp[i]);
    pq.push({dp[i], i});
}
*/  
using namespace std;

class Solution {
public:
//last k elmts mdhun max elmt kdhycha ahe so use priority queue
    int constrainedSubsetSum(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long>dp(n+1,INT_MIN);
        long long ans = INT_MIN;
        dp[0] = 0;
        priority_queue<pair<long long,long long>>pq;
        for (int i = 1; i <= n; ++i)
        {
            //gap should not exceed k
            while (!pq.empty() and pq.top().second < i-k)
            {
                pq.pop();
            }
            if(!pq.empty())
                dp[i] = pq.top().first;
            if(dp[i] < 0)
                dp[i] = 0;//as -ve val krun teh sum kmi krt ahet so 0 la set kra
            dp[i] += nums[i-1];
            ans = max(dp[i],ans);
            pq.push({dp[i],i});
        }
        return ans;
    }
};