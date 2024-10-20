/*
1st numeric quest arr = a[n] k = special number goal is to make k to 0 using fewest moves if impossible return -1
a = 1 1 4 2 3 k = 5
ans = 2
to remove last 2 elmts to reduce 5 t0 0
*/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
int first(vector<int> &a, int k)
{
    int sum = 0;
    for (auto &&i : a)
    {
        sum += i;
    }
    if (sum == k)
        return n;
    sum = 0;
    int target = sum - k;
    int maxi = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum > target)
        {
            sum -= a[j];
            j++;
        }
        if (sum == target)
            maxi = max(maxi, i - j + 1);
    }
    return maxi == 0 ? -1 : n - maxi;
}
/*
2nd que hierarchy validator we have inequality a > b ur task is to determine if its possible to assign values consistently to variables in stmts
i/p x>y y>z z>w o/p 1
i/p a>b b>c c>a o/p 0
*/
bool second(vector<string> &s)
{ // a>b ek str ase vec of str dile ahet
    int n = s.length();
    vector<int> adj[26];
    // if cycle present in graph return true
    for (int i = 0; i < n; i++)
    {
        string char = s[i];
        int u = char[0] - 'a'; // a>b a is 0th char is a 1st is sign(< >) 2nd is bconvert to int
        int v = char[2] - 'a';
        adj[u].push_back(v);
    }

    vector<int> vis(26, 0);
    vector<int> rec(26, 0);

    function<bool(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        rec[u] = 1;
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                if (dfs(v))
                    return 1;
            }
            else if (rec[v])
                return 1;
        }
        rec[u] = 0;
        return 0;
    };
    bool isCycle = 0;
    for (int i = 0; i < 26; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                isCycle = 1;
                break;
            }
        }
    }
    return !isCycle;
}
/*
3rd luminous passage quest
determining the radius of its illumination, effectively lighting up area from [pos-p+1,pos+p-1] switched on at position Pos
minimum number of lamps to be turned ON to light the whole tunnel
i/p 0 0 0 1 0 power = 3 o/p = - 1
i/p 0 0 1 1 1 0 0 1 power = 3 o/p = 2
turn at 2nd & 7th,2nd will cover [1,5] & 7th will cover [6,8]
*/

int third(vector<int> &a, int power)
{ // TC = O(N)
    // greedily  try to cover the tunnel from the start to the end.
    int n = a.size();
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        int right = -1; // farthest lamp that can cover the current position 'i'
        for (int j = min(n - 1, i + power - 1); j >= max(0, i - p + 1); j--)
        {
            if (a[j] == 1) // unfaluty lamp
            {
                right = j;
                break;
            }
        }
        if (right == -1)
            return -1;
        cnt++;
        i = right + power; // moves index i to next uncovered position after turning on a lamp at rightMostLamp
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
