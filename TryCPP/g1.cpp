
#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
      int n;
      cin>>n;
      
      string str;
      cin>>str;
      char letter = str[0];
      string ans = "";
      ans += str[0];
      for (int i = 1; i < n; ++i)
      {
         if (str[i] != letter)
            continue;
         else
         {
            letter = str[i + 1];
            ans += str[i + 1];
            i++;
         }
      }
            cout<<ans<<endl;
   }
   return 0;
}