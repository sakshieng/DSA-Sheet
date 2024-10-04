#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/maximum-xor_973113
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
using namespace std;

/* Given an array of numbers and a num x find the max value of (arr[i]^x) to solve this 
insert all num into trie in form of binary bits 
take x & find max no from array where (no^x) is maximum 
*/
//for our problem insert arr1 into trie and x will be every elmt from arr2 so do as arr2[0]^trie arr2[1]^trie
//TC O(n*32) for arr1 insertion + O(m*32)
struct Node{
    Node* links[2];//1st link for 2nd for 1

    Node() {
        links[0] = links[1] = NULL;
    }

    bool containsKey(int bit){
        //for checking the bit is set or not
        return (links[bit] != NULL);
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit){
        links[bit] = new Node();
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31;i >= 0;i--){
            // if bit is set
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                //doesnt contain bit
                node->put(bit);
            }
            node = node->get(bit);
        }
    } 
//we have designed a func to whom we will give num & it finds max from trie
int getMax(int num) {
    Node *node = root;
    int maxNum = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;  
        //for xor we want opposite of it
        if (node->containsKey(!bit)) {
            //it contains oppsite make this bit 1
            maxNum = maxNum | (1 << i);
            node = node->get(!bit);
        } else {
            node = node->get(bit);
        }
    }
    return maxNum;
}

};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    //we hvae entire trie ready with elmts of arr1
    for(auto &it:arr1) trie.insert(it);
    int maxi = 0;
    for(auto &it:arr2){
        maxi = max(maxi,trie.getMax(it));
    }
    return maxi;
}
