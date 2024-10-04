// https://leetcode.com/problems/design-authentication-manager/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class AuthenticationManager {
public:
//easy contest 2nd que
//we will use map
    int ttl;//time to live
    unordered_map<string,int>mp;
    AuthenticationManager(int timeToLive) {
        this->ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;//[] operator either inserts a new key-value pair if the key doesn't exist or updates the value if the key already exists. but insert stmt will not update the existing key-value pair
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp[tokenId] > currentTime)
            mp[tokenId] = currentTime + ttl;
        else
            mp[tokenId] = 0;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for(auto x:mp)
            if(x.second > currentTime)
                ans++;//that means these are not expired still exists even after curr time
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */