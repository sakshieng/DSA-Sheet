
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
//Sakshi codes here
using namespace std;
int main()
{
 string n;
    cin >> n;
    int count = 0;
    for (char c : n) {
        if (c == '4' || c == '7') {
            count++;
        }
    }
 
    if (count == 4 || count == 7)
       yes;
    else
        no;
    return 0;
}