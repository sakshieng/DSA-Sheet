#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-strong-pair-xor-ii/
using namespace std;

struct Node {
  Node * links[2];
  int cnt = 0;
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
  
};
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

public:
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node->get(bit)->cnt++;//increment cnt as we are adding elmt
            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit) && node->get(!bit)->cnt > 0) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

    void del(int x) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            int index = ((1 << i) & x) != 0;
            temp = temp->get(index);
            temp->cnt--;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        Trie trie;
        sort(begin(nums), end(nums));
        int j = 0,ans = 0;
        for(int i=0;i<nums.size();++i){
            trie.insert(nums[i]);
            while(nums[j]*2 < nums[i]){
                trie.del(nums[j]);
                j++;
            }
            ans = max(ans,trie.findMax(nums[i]));
        }
        return ans;
    }
};