#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int bs(vector<int>& s,int target){
        int left = 0,right = s.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if(s[mid] == target)
                return mid;
            else 
                if(s[mid] < target)
                    left = mid+1;
                else
                    right = mid-1;
        }
        return left;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //we can apply binary search on sorted array only
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int cnt = 0;
        for (int i = 0; i < g.size(); i++)
        {
            int idx = bs(s,g[i]);//as g[i] would be target
            if(idx < s.size())//valid
            {
                cnt++;
                s.erase(begin(s) + idx);//remove used cookie
            }
        }
        return cnt;
    }
};