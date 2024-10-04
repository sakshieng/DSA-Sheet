// https://codeforces.com/contest/1722/problem/C

#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    int n;cin>>n;
    set<string>row[3];
    string str;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> str;
            row[i].insert(str);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int score = 0;
        for(set<string>::iterator it = row[i].begin();it != row[i].end();++it){
            if (row[(i+1)%3].count(*it) and row[(i+2)%3].count(*it))
            {
                continue;
            }
            if (row[(i+1)%3].count(*it) or row[(i+2)%3].count(*it))
            
                score++;
            else
                score += 3;
        }
    cout << score << " ";
    }
    cout<< "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

    
