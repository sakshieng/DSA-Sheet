// https://leetcode.com/problems/string-to-integer-atoi/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while(i<n and s[i] == ' ') i++;
        if(i == n) return 0;
        //whatever the sign of int will be taken from the string
        int sign = 1;
        if(s[i] == '+' or s[i] == '-'){
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        long long int res = 0;
        while(i<n and s[i] >= '0' and s[i] <= '9'){
            res = res*10 + (s[i] - '0');
            if(res > INT_MAX or res < INT_MIN){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }//out of range
            i++;//move to next character
        }
        return sign*res;//return the result with sign
    }
};