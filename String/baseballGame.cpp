//https://leetcode.com/problems/baseball-game/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>scores;
        int size = 0;
        for(auto it:operations){
            if(it == "+"){
                scores.push_back(scores[size-1]+scores[size-2]);
                size++;
            }else if(it == "D"){
                scores.push_back(2*scores[size-1]);
                size++;
            } else if (it == "C") {
                size--;
                scores.pop_back(); 
            } else {
                scores.push_back(stoi(it));
                size++;
            }
        }
        int sum = 0;
        for(int i=0;i<size;++i){
            sum += scores[i];
        }
        return sum;
    }
};