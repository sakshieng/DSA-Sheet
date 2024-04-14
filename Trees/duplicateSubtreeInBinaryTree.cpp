//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
//https://leetcode.com/problems/find-duplicate-subtrees/description/
#include<bits/stdc++.h>
//could be done without map also
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
//serilization of subtrees into strings
map<string,int>mp;
string solve(TreeNode* root,vector<TreeNode*>&ans){
    if(!root)
        return "null";
    string s = solve(root->left,ans) + ',' + solve(root->right,ans) + ',' + to_string(root->val);//delimiter as ',' we are concateninating preorder if str are equal means we found duplicates
    mp[s]++;
    if(mp[s] == 2) 
        ans.push_back(root);
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans ;
        solve(root,ans);
        return ans;
    }
};