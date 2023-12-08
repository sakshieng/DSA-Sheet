#include<bits/stdc++.h>
//https://codedrills.io/problems/reverse-integer
using namespace std;

class reverseInteger{
public:
    long reverse(int num){
        long curr = num;
        long reversed = 0;
        bool isNeg = 0;
        if(curr < 0){
            isNeg = 1;
            curr *= -1;
        }
        while (curr > 0)
        {
            int digit = curr%10;
            reversed = 10* reversed + digit;
            curr /= 10;
        }
        if(isNeg)
            reversed *= -1;
        return reversed;
    }
};