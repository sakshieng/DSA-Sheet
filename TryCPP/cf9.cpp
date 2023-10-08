#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

int main()
{
   int a, b, n;
   cin >> a >> b >> n;
   int cnt = 1;
   vector<int> ans(n, -1);
   ans.push_back(b);
   for (int i = 0; i < n - 1; ++i)
   {
      ans.push_back(b - cnt);
      cnt++;
   }
   ans.push_back(a);
   for (int i = 0; i < n; ++i)
      cout << ans[i] << " ";
   cout << endl;
   return 0;
}