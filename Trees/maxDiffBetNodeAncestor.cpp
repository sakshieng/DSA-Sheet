// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
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
class Solution {
public:
vector<int>diff;
void solve(TreeNode* root,int mini,int maxi)
{
    if(!root){
        diff.push_back(maxi-mini);
        return;
    }
    mini=min(root->val,mini);
    maxi=max(root->val,maxi);
    solve(root->left,mini,maxi);
    solve(root->right,mini,maxi);
}
    int maxAncestorDiff(TreeNode* root) {
    if(!root) return 0;
    solve(root,INT_MAX,INT_MIN);
    int maxi=INT_MIN;
    for(auto &i:diff)
        maxi=max(maxi,i);
    return maxi;
    }
};