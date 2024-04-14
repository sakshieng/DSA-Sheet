#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// Write C++ Program to swap data using function templates
template<class T>
void swap(T *a,T *b)
{
    T t;
    t=a;
    a=b;
    b=t;
    return;
}
int main()
{
   int a,b;
   cout<<"Enter 2 nos.:"<<endl;
   cin>>a>>b;
   swap(a,b);
   cout<<"after swapping"<<" "<<"a is "<<" "<<a<<"b is "<<b;
   return 0;
}