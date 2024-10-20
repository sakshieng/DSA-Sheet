// https://codeforces.com/contest/1915/problem/D
// const int mod = 1e9 +  7
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;

        string s;
        cin >> s;
        queue<char> q;
        q.push(s[0]);
        q.push(s[1]);
        if (n > 2)
        {
            for (int i = 2; i < n - 1; i++)
            {
                if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd')
                { // c
                    if (s[i + 1] == 'a' || s[i + 1] == 'e')
                    { // v
                        q.push('.');
                        q.push(s[i]);
                    }
                    else
                    {
                        q.push(s[i]);
                    }
                }else{
                    q.push(s[i]);
                }
            }
        q.push(s[n-1]);//as we are not including last char in loop ad dit herer
        }
        while (!q.empty())
        {
            cout << q.front();
            q.pop();
        }
        cout << "\n";
    }
    return 0;
}
