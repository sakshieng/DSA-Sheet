
#include <bits/stdc++.h>
//Sakshi codes here
using namespace std;
int main()
{
long long t; 
cin>>t;
while(t--)
    {
      int n, k;
        cin >> n >> k;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int pro = 1;
        int i=0,j=0;
        bool flag = true;
        while(j<n)
        {
            pro*=a[j];
                j++;
            if(pro > k) 
            {
            pro /= a[i];
            i++;
            }
            if(pro == k) {
            flag = false;
            break;
            }
        }
        if(flag == true)  cout << "No" << endl;
        else cout<<"Yes"<<" "<<i<<" "<<j-1<<endl;
    }
    return 0;
}