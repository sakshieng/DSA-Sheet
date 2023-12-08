#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class calc
{
private:
    int a, b, c, d;

public:
    void takeValues(int num1, int num2, int num3, int num4)
    {
        a = num1;
        b = num2;
        c = num3;
        d = num4;
    }
    int calculate()
    {
        return a * b - c / d;
    }
};

int main()
{
    cout << "Please enter your values:\n";
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    calc calculateNow;
    calculateNow.takeValues(a, b, c, d);
    cout << calculateNow.calculate() << "\n";
    return 0;
}