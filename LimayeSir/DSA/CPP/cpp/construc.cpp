#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// constructor program
// here we done constructor overloading
class Number
{
    int x, y;
public:
    Number() // default
    {
        x = y = 0;
        cout << "\nDefective";
    }
    Number(int a)
    {
        x = r = a;
        cout << "\nPara 1";
    }
    Number(int a, int b)
    {
        x = a;
        y = b;
        cout << "\nPara 2";
    }
    Number(Number &t)
    {
        x = t.y;
        y = t.y;
        cout << "\nCopy";
    }
    ~Number()
    {
        cout << "\nDestructor";
    }
    void set()
    {
        cout << "\nx:";
        cin >> x;
        cout << "\ny:";
        cin >> y;
    }
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void setx(int a)
    {
        x = a;
    }
    void sety(int b)
    {
        y = b;
    }
    void swap()
    {
        int r = x;
        x = y;
        y = r;
    }
};
// defaukt value pass kelyat inline func defn
int main()
{
    Number a;
    Number b(5, 7);
    Number c;
    a.set();
    c = a.add(b);
    a.display();
    b.display();
    c.display();
    Number sub(Number & t);
    {
        return Number()
    }
    return 0;
}