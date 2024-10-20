// https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//curr subtree should be perfect for all ancestors of it to be perfect
//see at level 1 TreeNode 3's leftSubtree size (3) != rightSubtree size (1) so node 3 can't create perfect tree

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
public:
    //we need kth largest so store all subtrees in pq
    priority_queue<int, vector<int>, greater<int>>pq;//min heap
    int helper(TreeNode* root,int k){
        if(!root)
            return 0;
        int left = helper(root->left,k);
        int right = helper(root->right,k);
        
        if(left == -1 || right == -1 || left != right)
            return -1;
        if(pq.size() < k)
        {
            pq.push(left + right + 1);
        }else{
            if(pq.top() < left + right + 1)//it has to be k^th largest
            {
                pq.pop();
                pq.push(left + right + 1);
            }
        }
        return left + right + 1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        helper(root,k);
        if(pq.size() < k) 
            return -1;
        return pq.top();
    }
};