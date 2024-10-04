// Implement a hash table from scratch
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class HashTable {
public:
    vector<int> table;
    int size;

    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key, int value) {
        int index = hash(key);
        table[index] = value;
    }

    int get(int key) {
        int index = hash(key);
        return table[index];
    }
};

int main() {
    HashTable hashTable(10);
    hashTable.insert(5, 20);
    cout << hashTable.get(5) << endl;
    return 0;
}