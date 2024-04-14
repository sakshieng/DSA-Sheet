// arrays are continuous blocks of memory these are of static size
// vectors are arrays of dynamic size
#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
void printVec(vector<int> v)
{
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
// vector global declration gives 10^7 memory size as compared to local which gives 10^5 size
int main()
{
   vector<int> v;
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
     int x;
     cin>>x;
     printVec(v);
     v.push_back(x);
   }
   printVec(v);
   return 0;
}
// vector<int> v(10,3); means 10 times 3 will print
// v.pop_back() will remove last element
// when we copy arrays as there is copy of pointers hence change in a1 will reflect to a2
// but in vectors change in v2 will not reflect to v1
// vector<int>v2=v; has T.O. of O(n) which is more expensive like copying by loops
