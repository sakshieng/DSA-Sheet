#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
//using stack
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i < v.size();++i){
            //push all right dirnl asteroids
            if(v[i] > 0) st.push(v[i]);
            else{
                while(!st.empty() and st.top() < abs(v[i])) st.pop();

                if(!st.empty() and st.top() == abs(v[i])) st.pop();

                //if stack empty then there will not be any asteroid that destroy curr because evrything is destroyed
                else if(st.empty()) ans.push_back(v[i]);
            }
        }
        int i = ans.size();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        //we cant sort ans so will reverse the elmts from stack acc to size of ans
        reverse(ans.begin()+i,ans.end());
        return ans;
    }
};