#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solutions/4033214/99-32-greedy-heap-beginner-friendly-full-explanation-c-java-python/?envType=daily-question&envId=2023-09-12
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        //greedy
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        int cnt = 0;
        for(int i=24;i >= 0;i--){
            //check curr freq>=next freq
            if(freq[i] == 0){
                break;
            }
            if (freq[i] >= freq[i + 1]){
                int prev = freq[i];
                freq[i] = max(0,freq[i+1]-1);//reduce curr freq to make it 1 less than next freq
                cnt += prev-freq[i];
            }
        }
        return cnt;
    }
};