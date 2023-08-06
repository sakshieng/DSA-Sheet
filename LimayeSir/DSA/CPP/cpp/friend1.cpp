#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
class A;//forward declaration of class
class B
{
    int b;
public:
    void set();
    {
        cout<<"\nB b:"<<b;
        cin>>b;
    }
    void display()
    {
        cout<<"\nB b:"<<b;
    }
    void swap(A &);
};
class A
{
    int a;
public:
    void set()    
    {
        cout<<"\nA a"<<a;
        cin>>a;
    }
    void display()
    {
        cout<<"\nA a:"<<a;
    }
    friend void B::swap(A &);
};
void B::swap(A &m)
{
    int tmp=m.a;
    m.a=b;
    b=tmp;
}
int main()
{
   A p;
   B q;
   q.set();
   p.display();
   q.display();
   q.swap(p);
    //by above line decide to whom we have to declare as forward fun
   p.display();  
   q.display();  
   return 0;
}