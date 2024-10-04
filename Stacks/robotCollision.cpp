#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>ans;
        stack<int>st;
        int n = positions.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if(directions[i] == 'L')
            {
                st.push(positions[i]);
            }
            while (!st.empty() && -1*st.top() < positions[i])
            {
                    
            }
        }
        
    }
};