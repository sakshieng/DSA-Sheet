// https://maang.in/problems/Good-Numbers-23?resourceUrl=cs71-cp481-pl3270-rs23
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int n, k, q;
    cin >> n >> k >> q;
    
    vector<long long> prefixSum(1000001, 0);
    // find how many students like each number
    for (int i = 0; i < n; i++) {
        int l, r; 
        cin >> l >> r;
        prefixSum[l]++;
        prefixSum[r + 1]--;
    }

    // prefix sum
    for (int i = 1; i < 1000001; i++) {
        prefixSum[i] += prefixSum[i - 1];
    }
    
    vector<long long> goodCount(1000001, 0);
    for (int i = 0; i < 1000001; ++i) {
        if (prefixSum[i] >= k) {
            goodCount[i] = 1; // Set to 1 if the number is good
        }
    }
    // prefix sum of goodCount
    for (int i = 1; i < 1000001; ++i) {
        goodCount[i] += goodCount[i - 1];
        goodCount[i] %= mod; 
    }
    
    while (q--)
    {
        int l, r; 
        cin >> l >> r;
        cout << (goodCount[r] - goodCount[l - 1] + mod) % mod << "\n"; // Apply modulo to the difference
    }
    
    return 0;
}
