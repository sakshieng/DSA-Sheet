#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// sets inbuilt by red-black trees
/*
Given N strings print unique strings in lexiographical order
      abc
      ghj
      jkl
      ghj
      abc
      ghj
      abc
*/
// we can use maps but as freqn is not asked hence use sets
int main()
{
   set<string>s;
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
     string str;
     cin>>str;
     s.insert(str);
   }
//    print set directly as it is already sorted
for(auto value:s)
{
    cout<<value<<endl;
}
   return 0;
}
// same as of unordered_maps there is unordered_sets