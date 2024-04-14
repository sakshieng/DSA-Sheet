#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freq_map;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }
    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            int freq = cache[key].second;
            freq_map[freq].erase(pos[key]);
            freq++;
            freq_map[freq].push_front(key);
            pos[key] = freq_map[freq].begin();
            if (freq_map[minFreq].empty())
                minFreq++;
            return cache[key].first;
        }
        else
            return -1;
    }
    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            cache[key].first = value;
            int freq = cache[key].second;
            freq_map[freq].erase(pos[key]);
            freq++;
            freq_map[freq].push_front(key);
            pos[key] = freq_map[freq].begin();
            if (freq_map[minFreq].empty())
                minFreq++;
            return;
        }
        if (capacity == cache.size())
        {
            int key = freq_map[minFreq].back();
            cache.erase(key);
            pos.erase(key);
            freq_map[minFreq].pop_front();
        }
        cache[key] = {value, 1};
        freq_map[1].push_front(key);
        pos[key] = freq_map[1].begin();
        minFreq = 1;
    }
};
int main() {
    // LFUCache object with capacity 2
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; //  10
    cout << cache.get(2) << endl; //  20

    cache.put(3, 30);

    cout << cache.get(1) << endl; //  -1

    cout << cache.get(2) << endl; //  20
    cout << cache.get(3) << endl; //  30

    return 0;
}
