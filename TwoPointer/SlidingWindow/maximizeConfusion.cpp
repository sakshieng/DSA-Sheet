// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
int solve(string a,int k,char c){
        int ans=INT_MIN;
        int i=0,j=0;
        int n=a.size();
        int ct=0;
        while(j<n){
            if(a[j]==c)ct++;
            
            while(ct>k){
                if(a[i]==c)ct--;
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string a, int k) {
        int temp1=solve(a,k,'T');
        int temp2=solve(a,k,'F');

        return max(temp1,temp2);
    }
};