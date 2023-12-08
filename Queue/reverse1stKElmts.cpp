#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/reverse-first-k-elements-of-queue_982771?leftPanelTab=0
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    vector<int> arr;
    int n =q.size();
    int x=k;
    while(x--){
       arr.push_back(q.front());
        q.pop();
    }
    reverse(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++)
        q.push(arr[i]);
    for(int i=0;i<(n-k);i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
