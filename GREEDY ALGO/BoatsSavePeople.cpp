// https://leetcode.com/problems/boats-to-save-people/?envType=problem-list-v2&envId=e3hce697
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
  /*need at least n/2 boats it can carry at most 2 people at same time
  to sort arr we need O(nlogn) & every val has range upto limit which is 3*1e4 as count sort works on val of arr we can think about it 
  TC of count sort O(limit) SC O(n)
  people = [3 2 2 1] 
  count sort arr = [null 1 2 1]//no of occurences of elmt 0->not appeared
  */
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int>count(limit+1,0);
        for(int p:people)   
            count[p]++;
        //in count arr idx->weight of people val->no of occurences of that weight
        int idx = 0;
        for (int val = 0; val <= limit; val++)
        {
            while (count[val] > 0)
            {
                people[idx++] = val;
                count[val]--;
            }
        }
        int left = 0,right = people.size()-1,cnt = 0;
        while (left <= right)
        {
            if(people[left]+people[right] <= limit){
                cnt++;
                left++;
                right--;
            }else{
                right--;
                cnt++;
            }
        }
        return cnt;
    }
};