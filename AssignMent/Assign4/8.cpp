#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// Write C++ Program to add, subtract, multiply and divide two numbers using class template.
template<class T>
class A
{
    public:
    T n1,n2;
    A(T a,T b)
    {
      n1=a;
      n2=b;
    }
    void output()
    {
      cout<<"addition is "<<add()<<endl;
      cout<<"subtraction is "<<sub()<<endl;
      cout<<"division is "<<div()<<endl;
      cout<<"multiplication is "<<mul()<<endl;
    }
    T add(){
      return n1+n2;
    }
    T sub(){
      return n1-n2;
    }
    T div(){
      return n1/n2;
    }
    T mul(){
      return n1*n2;
    }
};
int main()
{
   A<int>value(10,2);
   cout<<"Results:"<<endl;
   value.output();
   return 0;
}