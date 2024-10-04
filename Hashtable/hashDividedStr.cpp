#include<bits/stdc++.h>
//https://leetcode.com/contest/biweekly-contest-138/problems/hash-divided-string/description/
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
    int n = s.length();
    int sz = n / k;
    string result = "";

    for (int i = 0; i < sz; ++i) {
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += s[i * k + j] - 'a';
        }
        int charr = sum % 26;
        result += char('a' + charr);
    }

    return result; 
    }
};
