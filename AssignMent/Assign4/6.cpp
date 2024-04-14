#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//Write C++ Program which will demonstrate use of function template overloading
template<class T>
void func(T p)
{
    cout<<"value of p is "<<p<<endl;
}
template<class T,class Q>
void func(T a,Q b)
{
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
}
int main()
{
   func(10);
   func(10,20);
   return 0;
}