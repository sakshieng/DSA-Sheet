#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// destructor cannot be called explicitly
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
class Result:private Student
{
    int mrk;
public:
    void input()
    {
        setData();
    }
    void output()
    {
        display();
    }
    int readNo()
    {
        return getNo();
    }
// ithe derivation type public ahe mg base class che private members 
    char *readNm()
    {
        return getName();
    }
    void setResult()
    {
        cout<<"\nMarks: ";
        cin>>mrk;
    }
    void displayResult()
    {
        cout<<"\nMarks: "<<mrk;
    }
    int getMark()
    {
        return mrk;
    }
};
// derived class cha object
int main()
{
   Result r;
   r.input();
   r.setResult();
   r.output();
   r.displayResult(); 
   return 0;
}