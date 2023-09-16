#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

bool sortt(int a,int b){
    return to_string(a)<to_string(b);
}
int main()
{
   int n;cin>>n;
   vector<int>a(n);
   for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),sortt);
     for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
   return 0;
}