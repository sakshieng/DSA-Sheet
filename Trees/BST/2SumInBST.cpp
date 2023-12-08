#include <bits/stdc++.h>
// 2 sum IV
// tc O(n) sc 2*O(h)
// refrence of BST iterator
//  https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
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
// this iterator will work for before & next
class BSTIterator
{
    stack<TreeNode *> st;
    // reverse->true=before reverse->false=after
    bool reverse = 1;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root); // reverse==1 -> right push
    }
    bool hasNext()
    {
        return st.empty() == 1 ? 0 : 1;
    }
    int next()
    {
        TreeNode *tmp = st.top();
        st.pop();
        if (!reverse)
            pushAll(tmp->right);
        else
            pushAll(tmp->left);
        return tmp->val;
    }
    void pushAll(TreeNode *node)
    {
        for (; node != nullptr;)
        {
            st.push(node);
            if (reverse == 1)
                node = node->right;
            else
                node = node->left;
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return 0;

        BSTIterator l(root, 0); // left=next
        BSTIterator r(root, 1); // right=before
        int i = l.next();
        int j = r.next();
        // simple 2 poniter
        while (i < j)
        {
            if (i + j == k)
                return 1;
            else if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return 0;
    }
};