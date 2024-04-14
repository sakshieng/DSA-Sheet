#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/add-binary-strings_893059?leftPanelTabValue=PROBLEM
string addBinaryString(string &a, string &b, int n, int m)
{
    string sum = "";

    int i = 0;
    int carry = 0;
    while (i < max(n, m))
    {
        int curSum = carry;
        if (i < n)
            curSum = curSum + (a[n - 1 - i] - '0');
        if (i < m)
            curSum = curSum + (b[m - 1 - i] - '0');
        sum.push_back((curSum) % 2 + '0');

        carry = curSum / 2;
        i++;
    }
    if (carry != 0)
        sum.push_back('1');

    reverse(sum.begin(), sum.end());
    return sum;
}