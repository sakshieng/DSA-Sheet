/*
You are given a BST, find elements in tree under a given range
*/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};
vector<int>rangeBST(Node* root,int lower,int upper){// function takes in root node of BST, as well as lower and upper bounds of range. It returns a list of all values in BST that are within given range
    vector<int>res;
    if(!root)
        return res;
    if(root->val >= lower && root->val <= upper)
        res.push_back(root->val);
    if(root->val > lower)
    {
        //apply recursion
        vector<int>leftRes = rangeBST(root->left,lower,upper);
        res.insert(res.end(),leftRes.begin(),leftRes.end());
    }
    if(root->val < upper)
    {
        vector<int>rightRes = rangeBST(root->right,lower,upper);
        res.insert(res.end(),rightRes.begin(),rightRes.end());
    }
    return res;
}

// implementation of queue using stack

class queue{
private:
    stack<int>st1,st2;
public:
    void enqueue(int x){
        st1.push(x);
    }
    int dequeue(){
        if(st1.empty() && st2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if(st2.empty())
        {
            //insert all from st1 to st2
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        int front = st2.top();
        st2.pop();
        return front;
    }
    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
    int front(){
        if(st2.empty())
        {
            //insert all from st1 to st2
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            
        }
        return st2.top();
    }
};

/*
Given an array of positive integers, each of which represents no of liters of water in that particular bucket, we have to make litres of water in every bucket equal. We are allowed to do two types of operations any no of times:
1->We can altogether remove a bucket from sequence
2->We can remove some water from a bucket

Task -> We have to tell minimum no of liters removed to make all buckets have same amount of water. C++

*/
int findGCD(vector<int>&a){
    int gcdd = a[0];
    for(int i = 1;i<a.size();++i)
        gcdd = __gcd(gcdd,a[i]);
    return gcdd;
}
int minLitresRemoved(vector<int>&buckets){
    int gcdd = findGCD(buckets);
    int totalLitRemove = 0;
    for(int i:buckets)
        totalLitRemove += (i-gcdd);//make it equal to gcdd of arr
    return totalLitRemove; 
}
int main(){
    vector<int> buckets = {12, 15, 18};  
    cout << "Minimum liters removed: " << minLitresRemoved(buckets) << endl;

    return 0;
}