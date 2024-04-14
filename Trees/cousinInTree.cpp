#include <bits/stdc++.h>
//https://leetcode.com/problems/cousins-in-binary-tree/
// https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
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
    int find_heigh_parent(TreeNode* curr,int &parent,int value,int height)
    {
        if(!curr)
            return 0;
        if(curr->val == value)
            return height;
        parent = curr->val;
        int left = find_heigh_parent(curr->left,parent,value,height+1);
        if(left)
            return left;
        parent = curr->val;
        int right = find_heigh_parent(curr->right,parent,value,height+1);
        return right;
    }
    // same depth but not same parent means they are cousin
    bool isCousins(TreeNode *root, int x, int y)
    {
        //root->val is parent so if x & y belong to same parent return 0
        if(root->val == x || root->val == y)
            return 0;
        int xParent = -1;
        int xHeight = find_heigh_parent(root,xParent,x,0);

        int yParent = -1;
        int yHeight = find_heigh_parent(root,yParent,y,0);

        if(xParent != yParent && xHeight == yHeight) 
            return 1;
        return 0;
    }
};