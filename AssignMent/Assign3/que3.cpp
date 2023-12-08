#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
// staff->typist-->regular
//              -->casual
//      ->officer
//      ->teacher
// Total parts:1)codename,2)subject,3)publication,4)grade,5)spped,6)daily wages
class staff
{
public:
    string codeName;
    staff() {}
    staff(string name)
    {
        codeName = name;
    }
    void display1()
    {
        cout << "Code name is " << codeName << endl;
    }
};
class teacher : public staff
{
public:
    string subject;
    string publication;
    teacher() {}
    teacher(string a, string b)
    {
        subject = a;
        publication = b;
    }
    teacher(string a, string b, string c) : staff(c)
    {
        subject = a;
        publication = b;
    }
    void display2()
    {
        cout << "Subject :" << subject << " and"
             << " Publication :" << publication << endl;
    }
};
class officer : public staff
{
public:
    int grade;
    officer() {}
    officer(int g)
    {
        grade = g;
    }
    officer(int g, string c) : staff(c)
    {
        grade = g;
    }
    void display3()
    {
        cout << "Grade :" << grade << endl;
    }
};
class typist : public staff
{
public:
    int speed;
    typist() {}
    typist(int s)
    {
        speed = s;
    }
    typist(int s, string c) : staff(c)
    {
        speed = s;
    }
    void display4()
    {
        cout << "Speed :" << speed << endl;
    }
};
class regular : public typist
{
public:
    regular(int val, string c) : typist(val, c) {} // speed and code name
};
class casual : public typist
{
public:
    int dailyWages;
    casual() {}
    casual(int d)
    {
        dailyWages = d;
    }
    casual(int d, int val, string c) : typist(val, c)
    { // daily wages,speed ,codename
        dailyWages = d;
    }
    void display5()
    {
        cout << "Daily wages :" << dailyWages << endl;
    }
};
int main()
{
    casual *C = new casual(40, 2, "Assignment");   // wages,spped,code name
    teacher *T = new teacher("PL", "Programming"); // subject,publication
    officer *O = new officer(5);                   // Grades
    staff *S;
    typist *TT;
    C->display1();
    T->display2();
    O->display3();
    C->display4();
    C->display5();
    return 0;
}