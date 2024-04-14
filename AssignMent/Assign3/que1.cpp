#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
// Multiple Inheritance
class Mangoes
{
public:
    int a;
    void setdata()
    {
        a = 34;
    }
    void display()
    {
        cout << "Number of mangoes are " << a << endl;
    }
};
class Apples
{
public:
    int b;
    void setdata()
    {
        b = 40;
    }
    void display()
    {
        cout << "Number of apples are " << b << endl;
    }
};
class Fruit : public Mangoes, public Apples
{
public:
    void doit()
    {
        Mangoes::setdata();
        Mangoes::display();
        Apples::setdata();
        Apples::display();
    }
    void calcFruits()
    {
        cout << "Total number of fruits in basket :" << a + b << endl;
    }
};
int main()
{
    Fruit *f;
    f->doit();
    f->calcFruits();
    return 0;
}