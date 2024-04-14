#include <bits/stdc++.h>
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=daily-question&envId=2023-10-24
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};
        // simple bfs on each level store max val wala node
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            int currLevelSize = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<currLevelSize;++i){
                TreeNode* node = q.front();
                q.pop();
                maxi = max(maxi,node->val);//store all max values in one variable
                if(node->right != NULL)
                    q.push(node->right);
                if(node->left != NULL)
                    q.push(node->left);
            }
            res.push_back(maxi);
        }
        return res;
    }
};