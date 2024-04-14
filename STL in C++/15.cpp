#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// unordered maps diff betn maps and unordered maps is:
// 1. inbuilt implementation unordered use inbuilt hash table while map use red-black trees
// here hash value of each key is calculated
// 2.TC of insertion and access is O(1) & .find(),.end(),.erase() have TC of O(1)
// 3.Should have valid keys datatype

//-m%k=m-(m-%k)
/* 
Given N strings and Q queries.In each query you are given a string print frequency of that string:
      def
      abc
      ghj
      jkl
      ghj
      abc
      ghj
      abc
      2
      abc
      ghj
*/
int main()
{
  unordered_map<string,int>m;
   int n;
   cin>>n;
   for(int i=0;i<n;++i)
   {
     string s;
     cin>>s;
    m[s]++;
   }
//    take input string for each query
int q;
cin>>q;
while(q--)
{
    string s;
    cin>>s;
    cout<<m[s]<<endl;
    // this time required query occured
}
   return 0;
}                
