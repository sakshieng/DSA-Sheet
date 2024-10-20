#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://www.interviewbit.com/blog/water-jug-problem/
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}
//Conditions are Z % GCD(X, Y) = 0 and X + Y > Z
bool waterJug(int x, int y, int z)
{
    if (x + y < z)
    {
        return false;
    }

    if (x == 0 and y == 0)
    {
        if (z == 0)
            return true;
        else
            return false;
    }

    if (z % gcd(x, y) == 0)
        return true;
    else
        return false;
}
int main(){
    int X = 3, Y = 5, Z = 4;
    bool ans = waterJug(X,Y,Z);
    //can fill it pr no
    cout << ans << "\n";
}