#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// runtime polymorphism with overriding of member func
class A
{
protected:    
    int a;
public:
    void set()    
    {
        cout<<"\nEnter value of a:";
        cin>>a;
    }
    void display()
    {
        cout<<"\nA a"<<a;
    }
};
class B:public A
{
protected:
    int b;
public:
    void set()    
    {
        cout<<"\nEnter value of b:";
        cin>>b;
    }
    void display()
    {
        cout<<"\nB b"<<b;
    }
};
class C:public B
{
protected:
    int c;
public:
    void set()    
    {
        A::set();
        B::set();
        c=a+b;
    }
    void display()
    {
        A::display();
        B::display();
        cout<<"\nC's c"<<c;
    }
};
// class A->2 B->4 C->6 bytes
int main()
{
   A aobj;
   aobj.set();
   aobj.display();
   B bobj;
   bobj.set();
   bobj.display();
   bobj.A::set();
   bobj.A::display();
   C cobj;
   cobj.set();
   cobj.display(); 
   return 0;
}