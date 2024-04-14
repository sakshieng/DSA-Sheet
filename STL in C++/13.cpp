#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
void print(map<int, string> &m)
{
  cout << m.size() << endl;
  for (auto &pr : m)
  {
    cout << pr.first << " " << pr.second << endl;
  }
}
int main()
{
  map<int, string> m;
  m[1] = "abc";
  m[4] = "gfg";
  m[5] = "sde";
  auto it = m.find(4);
  if (it == m.end())
  {
    cout << "NO VALUE";
  }
  else
  {
    cout << (*it).first << " " << (*it).second << endl;
  }
  //    find mdhla index nasel it will return m.end()
}
/* we can do auto it=m.find(4)
m.erase(it); that keyword will deleted
use if(it != m.end()) before m.erase(it) to avoid segementation fault of non-existing value of iterator
*/
// m["abcd"]="abcd"; have TC of s.size()*(log(n))