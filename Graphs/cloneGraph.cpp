// https://leetcode.com/problems/clone-graph/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        //take adj nodes of that node
        if(mp.find(node) == mp.end())//node is not in map
        {
            mp[node] = new Node(node->val,{});
            for(auto adj:node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return mp[node];
    }
};
// we have to traverse  entire graph.  N nodes and V edges
// TC-> O(N+V)
// SC->O(N) for the hashmap
