// https://maang.in/mocks/attempts/2183?problem_id=47
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
int solve(vector<int>&a)
{
    int maxi = INT_MIN;
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = i+1; j <= a.size(); j++)
        {
            if(a[j] > a[i]){
                maxi = max(maxi,j-i);
            }else {
                maxi = 0;
            }
        }
        
    }
    return maxi;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>a(n);
        for(auto &i:a) cin>>i;
        int ans = solve(a);
        if(ans == 0) {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else cout<<ans<<"\n";
    }
    return 0;
}