#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13

class Solution {
public:
//     one who is with greater rating from neighbouring will have more candies
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> c(n,1);
        for(int i=1;i<n;i++)
        if(r[i] > r[i-1])
//             left to right traverse
        {
            c[i]=c[i-1]+1;
        }
//         right to left traverse
        for(int i=n-2;i>=0;i--)
        if(r[i]>r[i+1])
        {
            c[i]=max(c[i],c[i+1]+1);
        }
        int candy=0;
        for(int i=0;i<n;i++)
        {
            candy+=c[i];
            
        }
        return candy;
    }
};