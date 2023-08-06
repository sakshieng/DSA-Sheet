#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// maps ordered
// map implementaion is done by using Red-black trees
// we cant do it+1 in maps(here we have keys)
int main()
{
   map<int,string> m;
   // int yane key ki datatype and string is value ki datatype
   m[1]="abc";
   m[5]="cde";
   m[3]="acd";
   m.insert({7,"afd"});
   map<int,string> :: iterator it;
   for(it=m.begin();it != m.end();++it)
   {
      cout<<(*it).first<<" "<<(*it).second<<endl;
   }
   // maps store keys in sorted order
   return 0;
}