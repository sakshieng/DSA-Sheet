/*
Given N strings abc
                def
                abc
                ghj
                jkl
                ghj
                ghj
                abc
print unique strings in lexographical order with their frequency
N<=10^5
|S|<=100
*/
#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
  map<string, int> m;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    string s;
    cin >> s;
    //  we can use m[s]=m[s]+1
    m[s]++;
  }
  for (auto pr : m)
  {
    cout << pr.first << " " << pr.second << endl;
  }
  return 0;
}
// keys are sorted acc lexographic order abc then def then ghj