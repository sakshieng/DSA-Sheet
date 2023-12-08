#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
class Shape
{
public:
    Shape() {}
    virtual void print()
    {
        cout << "This is a shape." << endl;
    }
};
class Polygon : public Shape
{
public:
    Polygon() {}
    void print()
    {
        cout << "Polygon is a shape." << endl;
    }
};
class Rectangle : public Polygon
{
public:
    Rectangle() {}
    void print()
    {
        cout << "Rectangle is a Polygon." << endl;
    }
};
class Triangle : public Polygon
{
public:
    Triangle() {}
    void print()
    {
        cout << "Triangle is a Polygon." << endl;
    }
};
class Square : public Rectangle
{
public:
    Square() {}
    void print()
    {
        cout << "Square is a Rectangle." << endl;
    }
};
int main()
{
    Shape S;
    Polygon P;
    Rectangle R;
    Triangle T;
    Square Sq;
    S.print();
    P.print();
    R.print();
    T.print();
    Sq.print();
    return 0;
}
