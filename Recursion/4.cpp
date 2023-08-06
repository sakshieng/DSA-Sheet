#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// ackeramnn func
int ackermann(int m,int n)
{
    if(m==0) return n+1;
    if(m>0 && n==0) return ackermann(m-1,1);
    if(m>0 && n>0) return ackermann(m-1,ackermann(m,n-1));
}
int main()
{
   int x=ackermann(1,2);
   cout<<x;
   return 0;
}