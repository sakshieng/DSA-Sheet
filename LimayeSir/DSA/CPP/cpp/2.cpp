#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//new operator
int main()
{
   int *ptr;
   ptr=new int;
   cout<<"\nEnter no:";
   cin>>*ptr;
   cout<<"\nNo: "<<*ptr;
   *ptr=*ptr+4;
   cout<<"\nNo:"<<*ptr;
   delete ptr;
   return 0;
}