#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//ptr having initial value is given at the time of declaration
int main()
{
   int *ptr;
   ptr=new int(10);
   cout<<"\nNo:"<<*ptr;
   *ptr=*ptr+5;
   cout<<"\nNo:"<<*ptr;
   delete ptr;
   return 0;
}