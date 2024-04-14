#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//grredy
//each child should receive smallest cookie that meets their greed
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(s),end(s));   
        sort(begin(g),end(g));   
        int receivedCookie = 0,cookieIdx = 0;
        while (cookieIdx < s.size() and receivedCookie < g.size())
        {
            if(s[cookieIdx] >= g[receivedCookie])
                receivedCookie++;
            cookieIdx++;
        }
        return receivedCookie;
    }
};