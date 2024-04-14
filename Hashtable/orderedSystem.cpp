// https://leetcode.com/problems/design-an-ordered-stream/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class OrderedStream {
public:
    map<int,string>mp;//obv we have to use ordered hash table
    int cnt;
    OrderedStream(int n) {
        cnt = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        mp.insert({idKey,value});
        vector<string>res;
        for(auto &val:mp){
            if(val.first == cnt)
            {
                cnt++;
                res.push_back(val.second);
            }
        }
        return res;
    }
};
