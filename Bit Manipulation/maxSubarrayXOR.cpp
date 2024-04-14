//given an array we have to divide an array in such a way that XOR should be maximum
//this code will be having TC as O(n^2) to reduce it into lesser complexity we have to use trie
#include <bits/stdc++.h>
using namespace std;

int findMaxXOR(const vector<int> &arr)
{
    int n = arr.size();
    int max_xor = 0;

    for (int i = 0; i < n; i++)
    {
        int cur_xor = 0;
        for (int j = i; j < n; j++)
        {
            cur_xor ^= arr[j];
            max_xor = max(max_xor, cur_xor);
        }
    }

    return max_xor;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            cin >> ans[i];
        int mxii;
        mxii = findMaxXOR(ans);
        cout << mxii << endl;
    }
}
/*
3
4
0 2 5 1
3
1 2 3
5
8 2 4 12 1
so output will be
7
3
14
*/