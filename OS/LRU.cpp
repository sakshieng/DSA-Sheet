//we cant use binary search as we dont know numbers are arranged in sorted order
//so we will use hashmap and doubly-LL
//no of hashes == no of pages 
//key value of the page and value is storing value of that node 
//when we are removing the cache we are updating the cache
//O(1) time complexity 
//searching for the page requested and required shifting is donein O(1) time
//time for query = O(1)+O(1)
#include<bits/stdc++.h>
//check soln easy
//as in doubly ended list we have to insert the pair which we are storing in hash
//the case is we are not found the elmt so we are erasing any key present from ll and updating the hash by erasing key 

using namespace std;
class LRUCache

{

    int capacity;

    unordered_map<int, list<pair<int,int>>::iterator> m;

    list<pair<int,int>> l;

public:

    LRUCache(int capacity)

    {

        this->capacity = capacity;

    }

 

    int get(int key)
    {
        if(m.find(key) == m.end())
            return -1;
        else{
            auto elmt = m[key];
            int val = elmt->second;
            l.erase(elmt);
            l.push_front({key, val});
            m[key] = l.begin();
            return val;
        }
    }
    void put(int key, int value)
    {

        if(m.find(key) != m.end()){

            l.erase(m[key]);

            m.erase(key);

        }

 

        if(capacity == l.size()){

            pair<int, int> last = l.back();

            l.erase(m[last.first]);

            m.erase(last.first);
            //as least recently used should be deleted from queue

        }

 

        l.push_front({key, value});

        m[key] = l.begin();

    }

};
int main() {
    // LRUCache object with capacity 2
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10
    cout << cache.get(2) << endl; // 20

    cache.put(3, 30);

    cout << cache.get(1) << endl; // -1

    cout << cache.get(2) << endl; // 20
    cout << cache.get(3) << endl; // 30

    return 0;
}
