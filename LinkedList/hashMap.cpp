// https://leetcode.com/problems/design-hashmap/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class MyHashMap
{
public:
    // linked list based implem chaining
    vector<list<pair<int, int>>> mp; // doubly LL
    int size = 100000;
    MyHashMap()
    {
        mp.resize(size);
    }
    // declaration of hash func
    int hash(int key)
    {
        return key % size;
    }
    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = mp[i].begin();
        while (it != mp[i].end())
        {
            // first -> key second -> value
            if (it->first == key)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value)
    {
        // not exist so put
        int i = hash(key);
        remove(key);
        mp[i].push_back({key, value});
    }

    int get(int key)
    {
        int i = hash(key);
        list<pair<int, int>>::iterator it = mp[i].begin();
        if (it == mp[i].end()) // doesn't exist
            return -1;
        else
            return it->second;
    }

    void remove(int key)
    {
        // check if exists then remove
        int i = hash(key);
        list<pair<int, int>>::iterator it = mp[i].begin();

        if (it != mp[i].end())
            mp[i].erase(it);
    }
};
