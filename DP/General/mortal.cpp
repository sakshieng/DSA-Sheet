// https://codeforces.com/problemset/problem/1418/C
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)


int memo(vector<int>&a,int i,bool flg,vector<int>&dp){
    
}


int solve(vector<int>&a,int idx,)
{
    //ai-> 0 easy ai->hard
    //i-1.i-2
    //where greedy approach fails
    //1 1 1 1 1 0->ans comes 3 but expected is 2
    int n = a.size();
    int ans = 0;
    bool myTurn = false;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 1){
            myTurn = 1;
            
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}