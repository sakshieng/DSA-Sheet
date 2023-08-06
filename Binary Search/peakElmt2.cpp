#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-a-peak-element-ii/description/ 

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int>ans;
        int upper=-1,left=-1,right=-1,lower=-1;
        for(int i=0;i<rows;++i){
            int l=0,h=cols-1;
            while(l<=h){
                int mid=l+(h-l)/2;

                if(i > 0) upper = mat[i][mid];
                else upper = -1;

                if(i < rows-1) lower = mat[i+1][mid];
                else lower=-1;

                if(mid > 0) left = mat[i][mid-1];
                else left = -1;

                if(mid < cols-1) right = mat[i][mid+1];
                else right = -1;

                //max half values
                int maxLeftHalf= max(left,mat[i][0]);
                int maxRightHalf = max(right,mat[i][cols-1]);

                if(mat[i][mid] >= max(max(upper,lower),max(left,right))){
                    ans.push_back(i);
                    ans.push_back(mid);
                    return ans;
                }else if(maxLeftHalf > maxRightHalf) h = mid-1;
                else l = mid+1;
            }
        }
        return ans;
    }
};
//TC->O(nlogm) SC->constant space O(1) apply BS on rows find middle row then first elmt of that row is greater of all check 