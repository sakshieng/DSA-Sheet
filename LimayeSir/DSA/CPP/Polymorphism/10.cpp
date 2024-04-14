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
        cout<<"\nC c";
    }
};
int main()
{
   A aobj;
   A *aptr;//A class pointer
   aptr=&aobj;
   aptr->set();
//    base pointer can hold any derived class object so aptr=&cobj 
   aptr->display();
   B bobj;
   aptr=&bobj;
   aptr->set();
   aptr->display();
    //base pointer hold krtoy derived class cha object if we dont wont to invoke methods of base but wont of derived then use typecasting 
//    begin part of derived object belongs to the base 
// invokation is by pointer will give member func of A
// invokation by typecasting will give derived version of class this typecasting is at the time of compilation
   ((B*)aptr)->set();
   ((B*)aptr)->display();
   C cobj;
   C *cptr=&cobj;
   cptr->set();
   cptr->display(); 
   return 0;
}