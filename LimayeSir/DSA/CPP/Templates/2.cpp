// those func having which are data type independent can be converted to templates
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template<class P,class Q>
void display(P &a,Q &b)
{
    cout<<"\ndata1: "<<a<<"\ndata2: "<<b;
}
// from template instance of P is created as integer to a
int main()
{
   int a=10;
   char b='A';
   double c=9.2;
   display(a,b);
   display(b,c);
   display(c,a);
   return 0;
}