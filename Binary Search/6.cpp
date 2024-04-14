#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// EKO PROBLEM
// https://www.spoj.com/submit/EKO/
// binary search applies on monotonic predicate func wood>=m-->T else -->F
// we have to find last true
// arrays having size greater tha N=1e6+10; should declared globally
const int N = 1e6 + 10;
int n;
long long m;
long long trees[N];
// h=height of wood to be cutted
bool isWoodSufficient(int h)//O(n) func call
{
    // at middle height h if suffiencient amount of wood gain then return tru or false
    long long wood = 0;
    for (int i = 0; i < n; ++i)
    {
        if (trees[i] - h >= 0)
        {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
    //  which is same as following
    // if(wood>=m)
    // return true;
    // else
    // return false;
}
int main()
{
    cin >> n >> m;
    // take input of trees height
    for (int i = 0; i < n; ++i)
    {
        cin >> trees[i];
    }
    long long lo = 0, hi = 1e9, mid;
    // max height of tree can be 10^9
    while (hi - lo / 2)
    {
        mid = lo + (hi - lo) / 2;
        // last true means we are getting m amount of tree and maximum height
        // T T T T T F F F F F
        if (isWoodSufficient(mid))
        {
            // if mid is let suppose 4th true then ans lies on right side
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (isWoodSufficient(hi))
    {
        cout << hi << endl;
    }
    else
    {
        cout << lo << endl;
    }
    return 0;
}
// TC------>O(N(log(H))) H-->max tree size N-->array size