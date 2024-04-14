// strings cant be assigned directly in func so we have to do overloading
// we cant swap strings using assignment operator
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template<class X>
void display(X &a,X &b)
{
    cout<<"\n"<<a<<"\t"<<b;
}
template<class P>
void aswap(P &a,P &b)
{
    P c=a;
    a=b;
    b=c;
}
void aswap(char *a,char *b)//regular wale baki 2 generic func ahet
{
    char t[100];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);
}
// we have overloaded swap func
int main()
{
   int a=5,b=20;
   display(a,b);
   swap(a,b); 
   char p[20]="Ganesh";
   char q[20]="Ramesh";
//    or we can dynamically input it in func
   display(p,q);
   swap(p,q); 
   display(p,q);
   return 0;
}