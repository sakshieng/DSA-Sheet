// https://practice.geeksforgeeks.org/problems/help-classmates--141631/1

#include <bits/stdc++.h> 
using namespace std; 

// class Solution{
    
//     public:
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
// };
int main()
{
    vector<int>a = {11,2,4,9,10,23};
    vector<int>ans = help_classmate(a,a.size());
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    
}
 vector<int> help_classmate(vector<int> arr, int n) 
{ 
    vector<int>ans;
    // ans.resize(-1);
    stack<int>st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        if(!st.empty()) 
            ans.push_back(st.top());
        st.push(arr[i]);

    }
    
    return ans;
} 