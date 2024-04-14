#include <bits/stdc++.h>
using namespace std;
// code by Sakshi
// multiple inheritance
// theory  oral
//      student
class Theory
{
protected:
    int t1,t2,t3;
public:
    Theory()    
    {
        t1=t2=t3=0;
    }
    ~Theory(){}
    void set()
    {
        cout<<"\nTheory marks:\n";
        cin>>t1>>t2>>t3;
    }
    void display()
    {
    cout<<"\nTheory marks "<<t1<<t2<<t3;
    }
    int total()
    {
        return t1+t2+t3;
    }
};
class Oral
{
protected:
    int o1,o2;
public:
    Oral()
    {
        o1=o2=0;
    }
    ~Oral(){}
    void set()
    {
        cout<<"\nOral marks:\n";
        cin>>o1>>o2;
    }
    void display()
    {
        cout<<o1<<o2;
    }
    int total()
    {
        return o1+o2;
    }
};
class Student:public Theory,public Oral
// the memory allocation order is followed acc like Theory first then Oral
{
protected:
    int no;
    char nm[15];
public:
    Student():Theory(),Oral()
    {
        no=0;
        nm[0]='\0';
    }
    ~Student(){}
    void set()
    {
        cout<<"\nRoll no: ";
        cin>>no;
        cout<<"\nName: ";
        cin>>nm;
        Theory::set();
        Oral::set(); 
    }
    void display()
    {
        cout<<no<<"\n";
        cout<<nm;
    }
};
int main()
{
   Student a;
   a.set();
   a.display(); 
   return 0;
}