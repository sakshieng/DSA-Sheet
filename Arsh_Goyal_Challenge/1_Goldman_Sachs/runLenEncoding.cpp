#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/run-length-encoding/1
string encode(string s)
{
    string ans = "";
    int counting = 0;
    for (int n = 0; s[n]; n++)
    {
        counting = 1;
        while (s[n] == s[n + 1])
        {
            counting++, n++;
        }
        ans += s[n] + to_string(counting);
    }
    return ans;
}