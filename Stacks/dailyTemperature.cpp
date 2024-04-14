// use of concept of next greater elmt
#include<bits/stdc++.h>
//https://leetcode.com/problems/daily-temperatures/description/
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(), 0);
        int n = temperatures.size();
        for(int i=n-1;i >= 0;i--){
            //popping all idx lower/eqaul temp than curr idx
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            //if stack has still elmts then larger temp exists and if no elmt in stack means for 76,76 we get 0 as ans
            if(!st.empty()){
                ans[i] = st.top()-i;//idx of elmt - inserting elmt cha idx
            }
            //curr elmt cha idx push kra stack mdhe 
            st.push(i);
        }
        return ans;
    }
};
/*
73 74 75 71 69 72 76 73
1   1  4  2  1  1  0 0
we are inserting idx of elmt
*/