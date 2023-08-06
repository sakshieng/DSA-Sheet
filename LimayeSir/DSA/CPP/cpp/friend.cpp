#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
class B;//forward declaration of class
// we are using friend(A &,B &) as it dont know B is separate class
class A
{
    int a;
public:
    void set()
    {
        cout<<"\nA a:";
        cin>>a;
    }    
    void display()
    {
        cout<<"\nA a:"<<a;
    }
    friend void swap(A &,B &);
};
class B
{
    int b;
public:
    void set();
    {
        cout<<"\nB b";
        cin>>b;
    }    
    void display()
    {
        cout<<"\nB b:"<<b;
    }
    friend void swap(A &,B &);
};
// less dependent swap vrti liha func
void swap(A &m,B &n)
{
    int tmp=m.a;
    m.a=n.b;
    n.b=tmp;
}
int main()
{
   A p;
   B q;
   p.set(); 
   q.set(); 
   p.display();
   q.display();
   p.swap(&p,&q);
   p.display();
   q.display();
   return 0;
}