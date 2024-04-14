/*for 1st tescase 2 is present in all dominos so we will pick that val which is present in all dominos 
              1 2 3 4 5 6
countTop      1 4   1
countBottom     3   1  1  1
countSame       1
for count of 2 = top+bottom-same = 4+3-1=6 which is same of 6
so where to be changed 2 in top/bottom as top has more occurances of 2 than bottom so do bottom walya 2 cha domino swap
no need to rotate in domino which have 2,2 on same sides
*/
#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int>countTop(7),countBottom(7),countSame(7);//freq array
        for(int i=0;i<n;++i){
            countTop[tops[i]]++;
            countBottom[bottoms[i]]++;
            if(tops[i] == bottoms[i])
                countSame[tops[i++]];
        }      
        int ans = n;//set to max value
        for(int i = 1;i <= 6;++i){
            if(countTop[i]+countBottom[i]-countSame[i]){
                int minSwap = min(countTop[i],countBottom[i]) - countTop[i];
                ans = min(ans,minSwap);
            }
        }
        return ans == n?-1:ans;
    }
};