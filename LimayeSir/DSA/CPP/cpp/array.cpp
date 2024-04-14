#include<bits/stdc++.h>
#include "array.h"
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

int main()
{
   Array k,p;
   k.setData();
   k.display();
   p.setData();
   p.display();
   if(p.isMore(70))
        cout<<"\nA grade";
   else
        cout<<"\nPass grade";//or failed or optimal marks
   if(p.isMore(k))        
         cout<<"\np is max";
   else      
         cout<<"\nk is max";
   return 0;
}