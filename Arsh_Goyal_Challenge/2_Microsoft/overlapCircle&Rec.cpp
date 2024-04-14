// https://leetcode.com/problems/circle-and-rectangle-overlapping/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //nearest point on rectangle to center of circle
        int xn = max(x1,min(x2,xCenter));
        int yn = max(y1,min(y2,yCenter));

        int dx = xn-xCenter,dy = yn-yCenter;
        return (dx*dx+dy*dy) <= (radius*radius);
    }
    //circle que (x2^2-x1^2)+(y2^2-y1^2) = r^2
};