// https://www.codingninjas.com/studio/problems/print-subsequences_624391?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

void solve(int i,char input[],string op,int s){
    if(i>=s){
        cout<<op<<"";
        cout<<endl;
        return ;
    }
    solve(i+1, input, op,s);
    op.push_back(input[i]);
    solve(i+1, input, op,s);
}
//another easy way of recursion
void print(int ind,vector<int>&ds,int arr[],int n){
    if(ind == n){
        for(auto it:ds){
            cout<< it <<" ";
        }
        cout<<endl;
        return;
    }
    //take particular idx to subseq
    ds.push_back(arr[ind]);
    print(ind+1,ds,arr,n);
    ds.pop_back();
}

void printSubsequences(char input[]) {
    string op="";
    int s = strlen(input);
    solve(0,input,op,s);
}
