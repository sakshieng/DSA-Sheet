#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   vector<int> v={2,4,5,6};
   for(int i=0;i<v.size();++i)
   {
    cout<<v[i]<<" ";
   }
   cout<<endl;
   vector<int>::iterator it=v.begin();
   //vector<int> container of whcih iterator is declred
   // we can iterate any container by using iterators
   //  cout<<(*(it+1))<<endl; this is for containers having finite or known index index 
   // following is universal one
for(it=v.begin();it!=v.end();++it)
{
   cout<<(*it)<<endl;
}
   return 0;
}
// it++-->next iterator and it+1-->next location