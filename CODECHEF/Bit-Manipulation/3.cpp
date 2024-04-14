#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long unsigned int num;
        cin >> num;
        bool flag = true;
        if (num <= 0)
            flag = false;

        if ((num & (num - 1)) != 0)
            flag = false;

        if ((num & 0x5555555555555555) != num)
            flag = false;

        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}