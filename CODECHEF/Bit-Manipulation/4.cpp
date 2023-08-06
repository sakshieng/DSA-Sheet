#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cin >> n;
    bool flag = true;
    if (n <= 0)
        flag = false;

    if ((n & (n - 1)) != 0)
        flag = false;

    if ((n & 0xAAAAAAAAAAAAAAAA) != 0)
        flag = false;

    if (flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}