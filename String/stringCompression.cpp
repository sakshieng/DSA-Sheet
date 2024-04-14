#include<bits/stdc++.h>
//https://leetcode.com/problems/string-compression/description/
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j,cnt;
        int n = chars.size();
        for(j=1,cnt =1;j <= n;++j,cnt++){
            if(j == n || chars[j] != chars[j-1]){
                chars[i++] = chars[j-1];
                //not appending the cnt when it is 0 or 1
                if(cnt >= 2)
                    for(char digit:to_string(cnt))
                        chars[i++] = digit;
                cnt = 0;
            }
        }
        return i;//length of ouput
    }
};