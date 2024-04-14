#include<bits/stdc++.h>
//https://leetcode.com/problems/design-hashmap/?envType=daily-question&envId=2023-10-04
using namespace std;

class MyHashMap {
public:
vector<int>keys,values;
 MyHashMap() {
    }
    
    void put(int key, int value) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
        keys.push_back(key);
        values.push_back(value);
    }
    
    int get(int key) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                keys.erase(keys.begin() + i);
                values.erase(values.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */