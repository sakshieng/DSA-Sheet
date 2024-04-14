// those func having which are data type independent can be converted to templates can be used when algorithm same
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template<class P>//p can be of any data type 
void display(P &a)
{
    cout<<"\ndata: "<<a;
}
// from template instance of P is created as integer to a
int main()
{
   int a=10;
   char b='A';
   double c=9.2;
   display(a);
   display(b);
   display(c);
   return 0;
}