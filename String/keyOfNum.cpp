#include<bits/stdc++.h>
//https://leetcode.com/contest/biweekly-contest-138/problems/find-the-key-of-the-numbers/
using namespace std;


class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string a = to_string(num1);
        string b = to_string(num2);
        string c = to_string(num3);

        while (a.length() < 4)
            a = '0' + a;
        while (b.length() < 4)
            b = '0' + b;
        while (c.length() < 4)
            c = '0' + c;

        string key = "";
        for (int i = 0; i < 4; ++i)
        {
            char mini = min({a[i], b[i], c[i]});
            key += mini;
        }

        while (key.length() > 1 && key[0] == '0')
        {
            key.erase(0, 1);
        }

        return stoi(key);
    }
};