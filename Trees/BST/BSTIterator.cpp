/*
next->we are starting with non-existent
hasNext->next node is there or noe for leaf node it returns 0
store inorder and then see n=both opn sc O(n) tc O(1)
required sc->O(H) tc O(1) pushing into stack n next calls and pushing n nodes so n/n
stack->empty hashNext=0
https://leetcode.com/problems/binary-search-tree-iterator/
*/

#include <bits/stdc++.h>
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
class BSTIterator
{
public:
    stack<TreeNode*>st;
    void pushAll(TreeNode* node){
        for(;node != NULL;st.push(node),node = node->left)
            ;
    }
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }
    //return smallest number
    int next()
    {
        TreeNode* node = st.top();
        st.pop();
        pushAll(node->right);// if there exists right push all the left
        return node->val;
    }

    bool hasNext()
    {
        return st.empty() == 1 ? 0 : 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */