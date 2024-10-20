#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    //w[i]*1+w[i]*2+w[i]*3+... =  w[i]*(1+2+3+...) = w[i]*(n*(n+1)/2)
    bool solve(long long time,vector<int>& workerTimes,int height){
        long long totalHeight = 0;
        for(int i:workerTimes){
        long long left = 0,right = 1e6;
        while(left <= right){
            long long mid = left + (right-left)/2;
            //for guessed time if all worker can finish reducing mountain -> if ys then try for smaller time or no -> try for larger time
            if(i*(mid*(mid+1)/2) <= time)
                left = mid + 1;
            else
                right = mid -1;
        }
        totalHeight += right;
        if(totalHeight >= height)
            return 1;
        }
        return 0;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        //height redn & time have monotonic reln
        long long l = 0,r = 1e16;
        while (l <= r)
        {
            long long m = l + (r-l)/2;

            if(solve(m,workerTimes,mountainHeight))
            {
                //if reduce try to small the time 
                r = m - 1;
                ans = m;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};