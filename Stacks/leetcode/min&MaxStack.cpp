#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/min-stack/
// https://aaronice.gitbook.io/lintcode/stack/max-stack
class MinStack {
public:
    stack<int>st;
    stack<int>minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = minStack.empty() ? val : min(val, minStack.top());
        minStack.push(minVal);
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


class MaxStack{
public:
    stack<int>st;
    stack<int>maxStack;
    MaxStack(){}
    void push(int val){
        int maxi = maxStack.empty() : val ? maxStack.top();
        maxStack.push(maxi);
        st.push(val);
    }
    int top(){
        return st.top();
    }
    void pop(){
        st.pop();
        maxStack.pop();
    }
    int getMax(){
        return maxStack.top();
    }
};

