//we will use map & array
#include<bits/stdc++.h>
//https://leetcode.com/problems/insert-delete-getrandom-o1/
using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>arr;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return 0;
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        //for O(1) TC we will take idx of elmt which is to be removed 
        if(mp.count(val)){
            int idx = mp[val];
            int v = arr.back();
            arr[idx] = v;
            mp[v] = idx;
            arr.pop_back();
            mp.erase(val);
            return 1;//successful removal    
        }
        return 0;
    }
    
    int getRandom() {
        int idx = rand()%arr.size();
        return arr[idx];//return random elmt by taking module we are taking limits which are avilable
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */