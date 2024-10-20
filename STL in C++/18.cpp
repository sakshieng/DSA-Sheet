#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// multisets-->uses red black trees
// we can do duplicates in case of multisets
void print(multiset<string> &s)
{ 
    for(string value:s)
    {
        cout<<value<<endl;
    }
}
int main()
{
   multiset<string> s;
   s.insert("abc");//O(log(n))
   s.insert("sdfa");
   s.insert("adf");
//  for deletion by this method iterator it ka abc delete hogq
auto it=s.find("abc");//O(log(n))
if(it != s.end())
{
    s.erase(it);
}
// if we use following then all "abc will be deleted"
// s.erase("abc");
   print(s);
   return 0;
}

