#include<bits/stdc++.h>
using namespace std;
// #define STUDENT_H_INCLUDED
class student
{
    int rno;
    char nm[15];
    double mrk;
    void setData();
    void setData(int);
    void setData(int,char *,double);
    void display();
    int getNo()
    {
        return rno;
    }
    double getMarks()
    {
        return mrk;
    }
};
  void student::setData()
    {
        cout<<"\nRoll No:";
        cin>>rno;
        cout<<"\nName:";
        cin>>nm;
        cout<<"\nMarks:";
        cin>>mrk;
    }
    void student::setData(int a)
    {
        rno=a;
        cout<<"\nName:";
        cin>>nm;
        cout<<"\nMarks:";
        cin>>mrk;
    }
    void student :: setData(int a,char *b,double c)
    {
        rno=a;
        strcpy(nm,b);
        mrk=c;
    }
    void student ::display()
    {
        cout<<"\nRoll No:"<<rno<<"\nName:"<<nm<<"\nMarks:"<<mrk;
    }



