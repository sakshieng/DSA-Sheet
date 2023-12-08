#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string R;
    cin >> R;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefix_sum(N + 1, vector<int>(N + 1, 0));

    
    dp[1][1] = 1;
    prefix_sum[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (R[i - 2] == '<') 
                dp[i][j] = prefix_sum[i - 1][j - 1];
            else 
                dp[i][j] = (prefix_sum[i - 1][i - 1] - prefix_sum[i - 1][j - 1] + MOD) % MOD;
            

            prefix_sum[i][j] = (prefix_sum[i][j - 1] + dp[i][j]) % MOD;
        }
    }

    int total = 0;
    for (int j = 1; j <= N; j++) {
        total = (total + dp[N][j]) % MOD;
    }

    cout << total << endl;

    return 0;
}
