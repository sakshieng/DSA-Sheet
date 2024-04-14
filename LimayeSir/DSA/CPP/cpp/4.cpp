#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//ptr is pointing towards array of instance
int main()
{
   int *ptr;
   ptr=new int[5];
   cout<<"\nData:\n";
   for (int i = 0; i < 5; i++)
   {
   //  cout<<*(ptr+i);
   cout<<ptr[i];
   }
   cout<<"\nData:\n";
   for (int i = 0; i < 5; i++)
   {
    cout<<ptr[i];
   }
   delete []ptr;
   return 0;
}
//*(x+2)<===>x[2] and (x+2)<===>&x[2]