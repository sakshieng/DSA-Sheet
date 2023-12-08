#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 0;
    int sum = 0;
    while (n != -1)
    {
        cin >> n;
        if (n >= 100)
        {
            sum++;
        }
        else
        {
            if (sum)
                cout << sum << "\n";
            sum = 0;
            if (n != -1)
                cout << n << "\n";
        }
    }
    return 0;
}