// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class KthLargest {
public:
//basic logic is whenever we want find kth smallest or kth larget elmt we will use PQ
// tc->O(k * log N),for finding kth elmt where N is the number of elements in the priority queue
    int k;
    priority_queue<int, vector<int>,greater<int>> hp; // Min heap for kth largest
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // hp.clear();
        for(int n:nums){
            hp.push(n);
        if(hp.size() > k)
            hp.pop();
        }
    }
    
    int add(int val) {
        hp.push(val);
        if(hp.size()>k)
            hp.pop();//we want kth largest elmt
        return hp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */