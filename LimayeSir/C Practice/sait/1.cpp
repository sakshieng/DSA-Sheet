#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://www.hackerrank.com/code-it-contest-22-1
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   sort(s1.begin(),s1.end());
   sort(s2.begin(),s2.end());
   if(s1==s2)
    cout<<"true"<<endl;
   else 
    cout<<"false"<<endl;
   return 0;
}