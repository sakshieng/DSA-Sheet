#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
    class Solution
    {
    public:
        int f(int n, vector<int> &dp)
        {
            if (n == 0 || n == 1)
            // when f(0)=0 and f(1)=1
            {
                return dp[n] = n;
            }
            if (dp[n] != -1)
            // it is ususal method to write dp as if it is not equal to -1 return as it is
            {
                return dp[n];
            }
            return dp[n] = f(n - 1, dp) + f(n - 2, dp);
        }
        int fib(int n)
        {
            vector<int> dp(n + 1, -1);
            int ans = f(n, dp);
            return ans;
        }
    };
   return 0;
}
/*
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countFibonacciLike(int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= k; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[k];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = countFibonacciLike(n, k);
        cout << ans << endl;
    }

    return 0;
}

*/