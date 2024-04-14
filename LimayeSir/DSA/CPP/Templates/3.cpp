#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// in swap func a and b are refernce variables
template<class P>
void aswap(P &a,P &b)//this is generic func where we are using template of class
{
    P c=a;
    a=b;
    b=c;
}
template<class X>
void display(X &a,X &b)
{
    cout<<"\n"<<a<<"\t"<<b;
}
int main()
{
   int a=10,x=20;
   char b='A',y='B';
   double c=9.2,d=9.4;
   display(a,x);
   aswap(a,x);
   display(a,x);
   return 0;
}