#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
class B;
class A
{
    int a;
public:
    void set()
    {
        cout << "\nA a" << a;
        cin >> a;
    }
    void display()
    {
        cout << "\nA a:" << a;
    }
    void swap(B &);
};
class B
{
    int b;

public:
    void set();
    {
        cout << "\nB b:" << b;
        cin >> b;
    }
    void display()
    {
        cout << "\nB b:" << b;
    }
    friend void A::swap(B &);
};
void A::swap(B &n)
{
    int tmp = a;
    a = n.b;
    n.b = tmp;
}
int main()
{
    A p;
    B q;
    q.set();
    p.display();
    q.display();
    p.swap(q);
    p.display();
    q.display();
    return 0;
}