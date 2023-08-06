    //Code by : SAKSHI
    const int INF = 1e9;
    const int MOD = 1e9 + 7;
    #define Sakshi ios_base::sync_with_stdio(false);
    #define sakshi cin.tie(NULL);
    #define ll long long
    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
    long long t; 
    cin>>t;
    while(t--)
        {
            ll n;
            cin>>n;
            ll a[n];
            for (int i = 0; i < n; i++)
            {
                cin>>a[i];
            }
            int cnt=0;
            for (int i = 0; i < n; i++)
            {
                if(a[i]==a[i++])
                cnt++;
            }
            if(cnt<n/2)        
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
        return 0;
    }