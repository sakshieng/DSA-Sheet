#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

int minTime(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int k = 0;
    while (k < n && k < m && s[k] == t[k])
    {
        k++;
    }

    if(k == 0) return n+m;
    else return n+m-k+1;
}

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << minTime(s, t) << endl;
    }
    return 0;
}
