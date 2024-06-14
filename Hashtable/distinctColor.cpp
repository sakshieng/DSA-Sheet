#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/solutions/
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballColor,colorCnt;
        unordered_set<int>distinctColors;
        vector<int>res;
        int cnt = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0],color = queries[i][1];
            if(ballColor.count(ball) > 0)//if ball already has a color
            {
                int oldColor = ballColor[ball];
                colorCnt[oldColor]--;
                if(colorCnt[oldColor] == 0){
                    distinctColors.erase(oldColor);
                }
            }
            //give new color to ball
            ballColor[ball] = color;
            colorCnt[color]++;
            distinctColors.insert(color);
            res.push_back(distinctColors.size());//every query with its distinct ball's color
        }
        return res;
    }
};