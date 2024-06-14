
#include <bits/stdc++.h>
using namespace std;
// https://maang.in/mocks/attempts/2588?problem_id=121
#define ll int64_t
#define endl '\n'

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->val = x;
    }
};

class Solution
{
public:
    int64_t alternateSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int64_t sum = 0;
        bool evenLevel = true;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (evenLevel)
                {
                    sum += node->val;
                }
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            evenLevel = !evenLevel;
        }
        return sum;
    }
};
