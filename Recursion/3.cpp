#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
int factorial(int);

int main()
{
    int n, res;
    cout << "Enter a non negative integer";
    cin >> n;
    res = factorial(n);
    cout << "Factorial of " << n << "=" << res;
    return 0;
}
int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
