#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/

class Solution {
public:
    bool valid(string &s,string &a,string &b,string &c){
    return s.find(a)!=string::npos && s.find(b)!=string::npos && s.find(c)!=string::npos;
}
    string minimumString(string a, string b, string c) {
        string total = a+b+c;
        string mini;
        do{
            if(valid(total,a,b,c)){
                if(mini.empty() || mini>total){
                    mini = total;
                }
            }
        }while(next_permutation(total.begin(),total.end()));
        return mini;
    }
};