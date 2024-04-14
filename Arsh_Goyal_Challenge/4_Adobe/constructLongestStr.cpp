// https://leetcode.com/problems/construct-the-longest-new-string/description/
// trying the math logic no explanation
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x == y)
            return (2*z) + (x*2)*2;
        return (2*z) + (min(x,y)*2)*2 + 2;
    }
};