#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// inheritance-->extension to an existing class reusability
using namespace std;
class Student
{
    int rno;
    char nm[15];
public:
    void setData()    
    {
        cout<<"\nRoll no: ";
        cin>>rno;
        cout<<"\nName: ";
        cin>>nm;
    }
    void display()
    {
        cout<<"\nRoll no "<<rno;
        cout<<"\nName "<<nm;
    }
    int getNo()
    {
        return rno;
    }
    char *getName()
    {
        return nm;
    }
};
// not specified private
class Result:    public               Student
//     derived    derivation type       base
{
    int mrk;
public:
    void setMarks()    
    {
        cout<<"\nEnter marks ";
        cin>>mrk;
    }
    int getMarks()
    {
        return mrk;
    }
    void displayResult()
    {
        cout<<"\nMarks "<<mrk;
    }
};
// memory allocation is acc to declaration so leading part is base class and trailing part is of derived class
int main()
{
   Student p;
   p.setData();
   p.display();
   Result q;
   q.setData();
   q.setMarks();
   q.display();
   q.displayResult();
   return 0;
}
// base 