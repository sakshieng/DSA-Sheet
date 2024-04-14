#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
void print(map<int,string>&m)
{
    cout<<m.size()<<endl;
    for(auto &pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}
int main()
{
   map<int,string>m;
   m[1]="abc";
   m[4]="gfg";
   m.insert({4,"afg"});
//    O(n) tc of this func
// unique keys are there in maps means if repeated key is there then next value replaced
   print(m);
   m[5]=4;
//  have tc O(log(n))  
   return 0;
}
// TC of insertion or access is n(log(n))