#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// vertical order traversal of a binary tree
// It is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column
/*
         9
3                     20
               5              6

Output:[3][9,5][20][6]
*/

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
    vector<vector<int>> ans;
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left != NULL)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right != NULL)
                q.push({node->right, {x + 1, y + 1}});
        }
        for (auto &i : nodes)
        {
            vector<int> tmp;
            for (auto &j : i.second)
            {
                tmp.insert(tmp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};