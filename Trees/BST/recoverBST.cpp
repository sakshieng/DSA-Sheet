#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree/description/
/*
2 nodes are swapped correct the BST
do traversal over tree sort it and keep pointer on traversal which will correct it
it has tc O(n)+O(nlogn)+O(n)
swapping 2 nodes in arr can have 2 cases->
1.swapping 2 adj node
3 5 8 7 10 15 20 25
so first vilation happens at 7 we will store pair 8,7 where violation happens & swap them

2.swapping 2 non-adj node
3 25 7 8 10 15 20 5
first violation at 7 store 25,7 then 2nd happens at 5 so swap 25 & 5
tc O(n) inorder sc O(1) morris traversal
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
private:
    // memober func
    TreeNode *first; 
    TreeNode *prev;
    TreeNode *last;
    TreeNode *middle;

public:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (prev != nullptr && (root->val < prev->val)) // for inorder to correct next guy has to be greater means this is case of viloation
        {
            // 1st violation mark these nodes as first & middle
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
            {
                // 1nd violation mark node as last
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN); // 1st elmt in inorder is always small
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};