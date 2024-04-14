// https://practice.geeksforgeeks.org/problems/help-classmates--141631/1

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        vector<int> ans(n, -1);
        
        for (int i = n-1; i>=0; i--){
            while (!st.empty() && st.top()>=arr[i])
                st.pop();
            
            if (!st.empty ())   ans[i] = (st.top());
            
            st.push(arr[i]);
        }
        return ans;
    } 
};

