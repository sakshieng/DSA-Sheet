#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//Write C++ Program to display largest among two numbers using function templates. 
template<class T>
int large(T a,T b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
   int a,b;
   cout<<"Enter 2 nos.:"<<endl;
   cin>>a>>b;
   cout<< large(a,b) << endl;
   return 0;
}