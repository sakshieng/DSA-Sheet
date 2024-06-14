// https://maang.in/mocks/attempts/2311?problem_id=60
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int solve(vector<int>&a,int k){
    int n = a.size();
    unordered_map<int,int>mp;
    for (auto &&i : a)
        mp[i]++;
    //freq in ascending order
    priority_queue<int,vector<int>,greater<int>>pq;//min heap
    for (auto &&i : mp)
    {
        pq.push(i.second);
    }
    //remove until k becomes <= 0
    while (k > 0)
    {
        k -= pq.top();//subtract freq of smallet elmt from k
        if(k >= 0) pq.pop();//remove smallest elmt if k is still +ve
    }
    return pq.size();
    
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout<<solve(a,m)<<endl;
    }
    return 0;
}