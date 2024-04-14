#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/fair-indexes_2181058?leftPanelTab=0
int totalIndexes(vector<int> &A, vector<int> &B) {
    // Write your code here.
    int n =A.size();
    int i=0,x=0,y=0,ans=0;
    while(i<n){
        x += A[i];
        y += B[i];
        i++;
    }
    if(x != y) return 0;
    int p=0,q=0;
    i=0;
    while(i < n-1){
        p += A[i];
        q += B[i];
        i++;
        if(p == q && p == x-q) ans++; 
    }
    return ans;
}
