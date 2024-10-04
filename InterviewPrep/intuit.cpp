// https://maang.in/mocks/attempts/6477?problem_id=100
// solved 2 questions which are good

#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

#define Sakshi           ios_base::sync_with_stdio(false);
#define Pro             cin.tie(NULL);

int main(){
    int t;cin>>t;while (t--)
    {
        Sakshi Pro;
        int n,k,cin>>n>>k;
        vector<int>a(n);
        for (auto &&i : a)
        {
            cin >> i;
        }
        // we can go on n,n-1,n-2 rides 
        vector<pair<int,int>>tokenLimit;
        for (int i = 0; i < a.size(); i++)
        {
            tokenLimit.emplace_back({a[i],n-i});
        }
        sort(begin(tokenLimit),end(tokenLimit));
        long long ans = 0;
        for (auto &&i : tokenLimit)
        {
            int cost = i.first, limit = i.second;
            if(k >= (cost*limit))
            {
                ans += limit;
                k -= (cost*limit);
            }else{
                ans += (k/cost);
                break;
            }
        }
        cout << ans << "\n";
    }
    
}