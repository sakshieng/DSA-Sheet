#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int solve(int a,int b,char Operator){
        if(Operator == '+') return a + b;
        else if(Operator == '-') return a - b;
        else if(Operator == '*') return (long)a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            string Operator = tokens[i];
            int ans = solve(operand1,operand2,Operator[0]);
            st.push(ans);
        }
        return st.top();
    }
};