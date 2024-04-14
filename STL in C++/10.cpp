#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// range based for loops and auto keywords
int main()
{
  vector<int> v = {2, 3, 4, 5, 6};
  for (int value : v)
  {
    cout << value << " ";
  }

  for (int value : v)
  {
    value++;
  }
  cout << endl;
  //    to dont get copy of vector use &
  for (int &value : v)
  {
    value++;
  }
  //    use of auto keyword
  for (auto it = v.begin(); it != v.end(); ++it)
  {
    cout << (*it) << " ";
  }
  cout << endl;
  vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
  for (auto &value : v_p)
  {
    cout << value.first << " " << value.second << endl;
    ;
  }
  auto a = 1.0;
  cout << a;
  return 0;
}