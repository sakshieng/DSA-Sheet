// same as Minimum time taken to BURN the Binary Tree from a Node
// https://www.codingninjas.com/studio/problems/time-to-burn-tree_630563
// https://practice.geeksforgeeks.org/problems/burning-tree/1
//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
//use of hashmap applying bfs the tree is burning same time means levelwise so we cant use dfs
//burn it and push it into the queue

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//at end if flg = 1 means i have burned who is adjacent to me so increase the time

class Solution {
  public:
  //farthest node from target is the time taken to burn whole tree
    int findMaxDistance(map<Node*,Node*>&mp,Node* target){
    queue<Node*>q;
    q.push(target);
    int time = 0;
    map<Node*,int>vis; // means those who are burned are marked as 1
    vis[target] = 1;
    while(!q.empty()){
        int size = q.size();
        int flg = 0; 
        for(int i = 0; i < size; ++i){
            auto node = q.front();
            q.pop();
            if(node->right && !vis[node->right]){
                flg = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(node->left && !vis[node->left]){
                flg = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(mp[node] && !vis[mp[node]]){
                flg = 1;
                vis[mp[node]] = 1;
                q.push(mp[node]);
            }
        }
        if(flg) 
            time++;
    }
    return time;
}

    //bfs to map parent
    Node* bfs(Node* root,map<Node*,Node*>&mp,int start){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            if(node->data == start)
                res = node; 
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>mp;
        Node* start = bfs(root,mp,target);
        int maxi = findMaxDistance(mp,start);
        return maxi;
    }
};
