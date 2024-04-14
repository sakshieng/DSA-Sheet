#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// sets yane keys ka collection
// -->1.normal 2.unordered 3.multisets
void print(set<string> &s)
{ 
    // print by range for based loops
    for(string value:s)
    {
        cout<<value<<endl;
    }
    // by auto
    for(auto it=s.begin();it!=s.end();++it)
    {
        cout<<(*it)<<endl;
    }
}
int main()
// TC of insert and access is log(n)
{
   set<string> s;
   s.insert("abc");
   s.insert("zsdf");
   s.insert("bcd");
   auto it = s.find("abc");
   if(it != s.end())
   {
     cout<<(*it);
   }
//    sets are more likely same as of maps
   return 0;
}