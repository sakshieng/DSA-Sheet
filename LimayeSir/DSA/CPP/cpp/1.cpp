#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// scope resolution operator
int a = 1000;
int main()
{
    int a = 1;
    {
        int a = 10;
        {
            int a = 100;
            cout << a << " " << ::a << endl;
        }
        cout << a << " " << ::a << endl;
    }
    cout << a << " " << ::a << endl;
    return 0;
}