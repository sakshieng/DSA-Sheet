// same as Minimum time taken to BURN the Binary Tree from a Node
// https://www.codingninjas.com/studio/problems/time-to-burn-tree_630563
// https://practice.geeksforgeeks.org/problems/burning-tree/1
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// ->1st approach
// bfs to map parent
// burn it and push it into the queue
// at end if flg = 1 means i have burned who is adjacent to me so increase the time
// farthest node from target is the time taken to burn whole tree
// storing in map means those who are burned are marked as 1

// ->2nd approach
// use of hashmap applying bfs the tree is burning same time means levelwise so we cant use dfs

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // convert to graph & do dfs
    int maxi = 0;
    int dfs(Node *root, int start)
    {
        int depth = 0;
        if (!root)
            return depth;
        int leftDepth = dfs(root->left, start);
        int rightDepth = dfs(root->right, start);

        if (root->data == start)
        {
            maxi = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if (rightDepth >= 0 and leftDepth >= 0)
        {
            depth = max(leftDepth, rightDepth) + 1;
        }
        else
        {
            int ans = abs(rightDepth) + abs(leftDepth);
            maxi = max(ans, maxi);
            depth = min(leftDepth, rightDepth) - 1;
        }
        return depth;
    }
    int minTime(Node *root, int target)
    {
        dfs(root, target);
        return maxi;
    }
};
