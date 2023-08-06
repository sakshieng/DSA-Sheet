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
class Result:public Student
{
protected:
    int mrk;
public:
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
        cout<<"\nEnter marks: ";
        cin>>mrk;
    }
    void display()
    {
        cout<<"\nMarks: "<<mrk;
    }
};
// int main()
// {
//    Result r;
//    r.Student::setData();
//    r.setData();
//    r.Student::display();
//    r.display();
//    return 0;
// }.
void main()
{
    Result r;
    r.Student::setData();
    r.setData();
    r.Student::display();
    r.display();
    Result a(13,"sakshi",12);
    a.Student::display();
    a.display();
}