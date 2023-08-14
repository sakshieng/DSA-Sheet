// https://www.hackerrank.com/contests/codefusion-22-07/challenges/wakanda-forever-1-3
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#define ll long long

#include <bits/stdc++.h>
using namespace std;
//senior's method
void solve(){
    ll n, x;
	cin >> n >> x;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		if(i % 3 == 0 && i != n) ans += (arr[i - 1] + arr[i - 2] + arr[i - 3]);
		ans += arr[i - 1];
	}
	if(ans <= x * 24) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        ll n,x;
        cin>>n>>x;
        // multiply by no of hrs in 1 day
        ll timeleft=x*24;
        vector<ll>v(n);
        for(auto &&i:v)cin>>i;
        sort(v.begin(),v.end());
        ll cnt=0,sum=0,finalsum=0;
        for (int i = 0; i < n; i++)
        {
            sum=sum+v[i];
            cnt++;
            if(cnt%3 == 0)
            // as we dont have to add last grp of set as after that no need to consider rest time for break
            {
                sum=sum*2;
                finalsum+=sum;
                sum=0;
                // again set sum to 0
            }
        }
        int sub=0;
        for(int i=n-1;i>=n-3;i--)
        // traversing of loop in reverse dirn
        {
            sub+=v[i];
        }
        if(n%3==0) finalsum-=sub;
            if(timeleft>=finalsum) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        
    }
    return 0;
}