// Code by : SAKSHI
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'u' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o')
            {
                cnt++;
            }
                if (cnt > 2)
                {
                    cout << "Happy" << endl;
                    break;
                }
                else
                {
                    cnt = 0;
                }
            if(cnt >= 2)
        cout << "Sad" << endl;
        }
    }
    return 0;
}