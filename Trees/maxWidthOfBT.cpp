// width = max no of nodes in that level
// width = idx of right node - idx of left node + 1
// the intution of 2*i+1 and 2*i+2 is coming from segment tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    long long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        //do level order tarversal
        queue<pair<TreeNode*,long long>>q;
        if(!root) return 0;
        int ans = 0;
        q.push({root,0});
        while (!q.empty())
        {
            long long n = q.size();
            long long mini = q.front().second;//to make idx of teee starting from 0
            long long first,last,i=0;
            for(int i=0;i<n;++i){
                long long currIdx = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0)
                    first = currIdx;
                if(i == n-1)
                    last = currIdx;
                if(node->left)
                    q.push({node->left,currIdx*2+1});
                if(node->right)
                    q.push({node->right,currIdx*2+2});
            }
            ans = max(ans,static_cast<int>(last - first + 1));//+1for the root
        }
        return ans;
    }
};