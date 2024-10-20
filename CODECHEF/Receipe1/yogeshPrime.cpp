// https://www.naukri.com/code360/problems/yogesh-and-primes_16331?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// we need to find integer P such that closest integer A & at least K prime in rnage [A,P]

const int maxn = 1000000;
vector<int> isPrime(maxn + 1, 1);
vector<int> primeCnt(maxn + 1, 0);

void sieve()
{
    isPrime[0] = isPrime[1] = 0; // 0 & 1 no prime
    for (int i = 2; i * i <= maxn; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                isPrime[j] = 0; // Mark all multiples of i as non-prime
            }
        }
    }
    // pref sum of prime cnt
    for (int i = 1; i <= maxn; ++i)
        primeCnt[i] = primeCnt[i - 1] + isPrime[i];
}
// find minimum P such that there are at least K primes in [A, P]
int findP(int a, int b, int k)
{
    int low = a, high = b, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int primeInRange = primeCnt[mid] - primeCnt[a - 1];
        if (primeInRange >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // precompute prime using sieve
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = findP(a,b,k);
        cout << ans << "\n";
    }
    return 0;
}