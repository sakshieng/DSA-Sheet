#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// single inheritance with public derivation
// *1.Use of protected members
// *2.constructor func
class Student
{
protected:
    int no;
    char nm[15];
public:
    Student()        
    {
        no=0;
        nm[0]='\0';
    }
    Student(int a,char *b)
    {
        no=a;
        strcpy(nm,b);
    }
    ~Student(){}
    void setData()
    {
        cout<<"\nRoll no: ";
        cin>>no;
        cout<<"\nName: ";
        cin>>nm;
    }
    void setData(int a)
    {
        no=a;
        cout<<"\nName: ";
        cin>>nm;
    }
    void display()
    {
        cout<<"\nNo: "<<no;
        cout<<"\nName: "<<nm;
    }
    int getNo()
    {
        return no;
    }
    char *getName()
    {
        return nm;
    }
};
// constructor for derived 
// 19 byte cha object asnar
// jya class cha object tych class chi method call hoil mhnje override hone
class Result:public Student
{
protected:
    int mrk;
public:
// we have added constructor as well for inheritance for initializing members
    Result():Student()    
    {
        mrk=0;
    }
    // ithun student cha constructor call zhala
    Result(int a,char *b,int c):Student(a,b)
    {
        mrk=c;
    }
    ~Result(){}
    int getMarks()
    {
        return mrk;
    }
    void setData()
    {
        Student::setData();
        cout<<"\nEnetr marks: ";
        cin>>mrk;
    }
    // void setData()
    // {
    //     cout<<"\nRoll no: ";
    //     cin>>no;
    //     cout<<"\nName: ";
    //     cin>>nm;
    //     cout<<"\nMarks: ";
    //     cin>>mrk;
    // }
    void setData(int a)
    {
        Student::setData(a);
        cout<<"\nMarks: ";
        cin>>mrk;
    }
    // void setData(int a)
    // {
    //     no=0;
    //     cout<<"\nName: ";
    //     cin>>nm;
    //     cout<<"\nMarks: ";
    //     cin>>mrk;
    // }
    void display()
    {
        Student::display();
        cout<<"\nMarks: "<<mrk;
    }
    // void display()
    // {
    //     cout<<"\nRoll no: "<<no<<"\nName: "<<nm<<"\nMarks: "<<mrk;
    // }
};
int main()
{
   Result r;
   r.setData();
   r.display();
   return 0;
}
