
const int INF = 1e9;
const int MOD = 1e9 + 7;
#define Sakshi ios_base::sync_with_stdio(false);
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> om(n), addy(n);
        for (int i = 0; i < n; i++) {
            cin >> om[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> addy[i];
        }
        
        int cnt1 = 0, cnt2 = 0;
        int maxi1 = 0, maxi2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (om[i] > 0) {
                maxi1++;
            } else {
                maxi1 = 0;
            }
            cnt1 = max(cnt1, maxi1);
            
            if (addy[i] > 0) {
                maxi2++;
            } else {
                maxi2 = 0;
            }
            cnt2 = max(cnt2, maxi2);
        }
        
        if (cnt1 > cnt2) {
            cout << "OM" << endl;
        } else if (cnt1 < cnt2) {
            cout << "ADDY" << endl;
        } else {
            cout << "DRAW" << endl;
        }
    
    }
    return 0;
}