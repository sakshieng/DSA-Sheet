#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/1850/problem/F
typedef long long ll;


int main() {
    long long int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin>>n;
        unordered_map<long long int,long long int>mp;
        for(long long int i=0;i<n;++i){
            long long int a;cin>>a;
            mp[a]++;
        }
        vector<long long int>jumps(n+1,0);
        for(long long int i=1;i<=n;++i){
            if(mp[i]){
                int j = i;
                while(j <= n){
                    jumps[j] += mp[i];
                    j += i;
                }
            }
        }
        cout<<*max_element(jumps.begin(),jumps.end())<<endl;
    }

    return 0;
}
