#include<bits/stdc++.h>
// https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/
using namespace std;

class Solution {
public:
//tc O(n) sc O(n)
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i) mp[nums[i]].push_back(i);
        int smallestMaxGap = INT_MAX;
        for(auto &[key,pos]:mp){
            //add one more pos to handle circular
            pos.push_back(pos[0]+n);
            int maxGapForOcc = 0;
            for(int i=1;i<pos.size();++i){
                maxGapForOcc = max(maxGapForOcc,abs(pos[i]-pos[i-1]));
            }
            smallestMaxGap = min(smallestMaxGap,maxGapForOcc);
        }
        return smallestMaxGap/2;
    }
};
/*if x appears at posi i & j it will take (j-i)/2 sec to make all num betn i & j equal to x
time depends on max gap betn number 
for arr 3 4 5 6 3 it will take 2 sec if we add  4 5 6 3 t this arr still it will take 2 sec as we can replace the elmts simultaneously in first arr 2sec and at same time in 2nd arr 2sec
but if we add 4 5 6 7 7 3 to that arr it will take 3 sec in 2nd arr and 2 sec in 1st arr but at same time hence time = 3

here we have to find gap for circular arr
1st method copy arr one more time at end
3 4 5 6 3
->
3 4 5 6 3 3 4 5 6 3 (2n)size elmts betn first occurence of 3 and last occur of 3 are 8
2nd method just add one more pos->first occurence+nums.size()
3 4 5 6 3
postions of 3->0,4,5(0+5)
of 4->1,6(1,6) we can find gap by these idx

use hash table store all pos of elmt in map
3->0,4,5
4->1,6
5->2,7
6->3,8
min gap=4 return gap/2
*/
