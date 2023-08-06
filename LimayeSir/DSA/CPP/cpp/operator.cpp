//a class object
#include<bits/stdc++.h>
// operator overloading
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// + is binary operator memeber func defn
class Result
{
    int rno;
    int mrk;
public:
    Result()
    {
        rno=mrk=0;
    }
    Result(int a,int b)
    {
        rno=a;
        mrk=b;
    }
    Result(Result &t)
    {
        rno=t.rno;
        mrk=t.mrk;
    }
    ~Result(){}
    // implicit call for parametrized constructor
    void set()
    {
        cout<<"\nRoll no:";
        cin>>rno;
        cout<<"\nMarks:";
        cin>>mrk;
    }
    void display()
    {
        cout<<"\nRoll no:"<<rno<<"\nMarks"<<mrk;
    }
    int getNo()
    {
        return rno;
    }
    int getMrk()
    {
        return mrk;
    }
    // sizeof membership(. *) scope-resolution <-- cant define behaviour
    // + ya operator che behaviour define keley
    // k new local member object result ya data type cha k object
    Result operator +(int m)
    {
        Result k(rno,mrk+m);//as only marks are getting changed
        return k;
    }
    Result operator -(int m)
    {
        Result k(rno,mrk-m);
        return k;
    }
    int operator >(Result &t)
    {
        return rno>t.rno;
    }
    int operator <(Result &t)
    {
        return rno<t.rno;
    }
    int operator ==(Result &t)
    {
        return rno==t.rno;
    }
    // < > == are for comparsion of returning type result a==b
    int operator >(int m)  
    {
        return mrk>m;
    }
    int operator <(int m)  
    {
        return mrk<m;
    }
    int operator ==(int m)  
    {
        return mrk==m;
    }
    // now above 3 are for comparsion of marks a>13 13 marks peksha jast kiti lok
};
int main()
{
   Result a(5,13),b;
   a.display();
   b=a+5;
   b.display();
   if(a>13)
        a.display();
   else
        b.display();         
   return 0;
}