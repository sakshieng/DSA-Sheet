#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   int n;
   cin>>n;
   int i=0,j=0;
   for(i=0;i<n;i++)
   {

   if(i%2!=0)
   {
    for(int j=0;j<i;j+=1)
    {
    cout <<65+j<<" ";
    }
    cout<<"\n";
   }
   else
   {
    for (j=0;j<i;j+=1)
    {
    cout<<90-j<<endl;
    }
    cout<<"\n";
   }
   }
   return 0;
}