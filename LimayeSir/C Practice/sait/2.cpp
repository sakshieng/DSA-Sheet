#include <bits/stdc++.h>
using namespace std;
int main()
{
   int i = 0, m, n;
   int matrix[m][n];
   cin>>m>>n;
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> matrix[i][j];
      }
   }
   int j = n - 1;
   int target;
   cin >> target;
   while (i < m && j >= 0)
   {
      if (matrix[i][j] == target)
      {
         cout << 1 << endl;
      }
      else if (matrix[i][j] > target)
      {
         j--;
      }
      else
      {
         i++;
      }
      cout << 0 << endl;
   }
   return 0;
}