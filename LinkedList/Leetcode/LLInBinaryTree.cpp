// https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-20
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool dfs(ListNode* head,TreeNode* root){
        if(!head)
            return 1;//all nodes in list are matched
        if(!node)
            return 0;
        if(head->val != root->val)
            return 0;
        
        return dfs(head->next,root->left) || dfs(head->next,root->right);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if(!root)
            return 0;
        if(dfs(head,root))
            return 1;
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};