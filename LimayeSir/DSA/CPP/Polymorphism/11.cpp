#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// virtual func  base pointer jya obj che method call krto te method yetil
class A
{
protected:    
    int a;
public:
    virtual void set()    
    {
        cout<<"\nEnter value of a:";
        cin>>a;
    }
    virtual void display()
    {
        cout<<"\nA's a "<<a;
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
        cout<<"\nB's b "<<b;
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
        cout<<"\nC's c";
    }
};
int main()
{
   A aobj;
   A *aptr;
   aptr=&aobj;
   aptr->set();
   aptr->display();
   B bobj;
   aptr=&bobj;
   aptr->set();
   aptr->display();
   aptr=new C;
//    new operator ne class object create kru shkto  
// tyach class cha obj tyach class cha pointer no cross
   aptr->set();
   aptr->display(); 
   return 0;
}