#include <bits/stdc++.h>
// u are given N processes with their burst times and arrival times = 0 print waiting and turn around for it

using namespace std;
vector<vector<int>> findScheduling(int n, vector<int> &burstTime)
{
    vector<int> tat(n); // turn around
    vector<int> wt(n); // waiting
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += burstTime[i];
        tat[i] = ans;
    }
    for (int i = 0; i < n; ++i)
    {
        wt[i] = tat[i] - burstTime[i];
    }
    vector<vector<int>> final;
    final.push_back(wt);
    final.push_back(tat);
    return final;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for (int i = 0; i < n; ++i) cin>>arr[i];
        vector<vector<int>>ans = findScheduling(n,arr);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) 
                cout<<ans[i][j]<<" ";           
            cout<<"\n";                
        }
    }
    return 0;
}
/*
1
5
4 6 7 2 1
*/