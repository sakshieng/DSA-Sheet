#include<bits/stdc++.h>
//https://leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/1093766530/?envType=daily-question&envId=2023-11-07
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        for(int i=0;i<speed.size();++i){
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(begin(time),end(time));
        int t = 0,ans = 0;
        for(double a:time)
            if(a <= t)
                break;
            else
                ans++,t++;
        return ans;
    }
};
