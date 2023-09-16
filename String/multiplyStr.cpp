#include<bits/stdc++.h>
//https://leetcode.com/problems/multiply-strings/description/
// https://practice.geeksforgeeks.org/problems/multiply-two-strings/1
// check gfg soln more advanced
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--){
            int  carry = 0;
            for(int j=num2.size()-1;j>=0;j--)
            {
                int tmp = (sum[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                sum[i+j+1] = tmp%10+'0';
                carry = tmp/10;
            }
            sum[i] += carry;
        }
        //means if ans is of 6-digit 054328 then samor che 0 remove kra 54328 return kra
        int pos = 0;
        while(pos < sum.size() && sum[pos] == '0') pos++;
        if(pos == sum.size()) return "0";
        return sum.substr(pos);
    }
};
/*
tc O(nm) sc O(1) max integers in arr=n+m
*/