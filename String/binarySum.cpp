#include<bits/stdc++.h>
//https://codedrills.io/problems/binary-sum
//tc O(N+M)
using namespace std;

class BinarySum{
public:
    string getBinarySum(string num1,string num2){
        string ans = "";
        int sum = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        while (i>=0 || j>=0 || sum != 0)
        {
            if(i >= 0)
                sum += num1[i]-'0';
            if(j >= 0)
                sum += num2[i]-'0';
            ans.push_back(char(sum%2 + '0'));
            sum = sum/2;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
