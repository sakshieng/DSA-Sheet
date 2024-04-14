// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

struct TreeNode
{
    long long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>m;
        preOrder(root,m);
        return ans;
    }
    void preOrder(TreeNode* root,unordered_map<int,int>&m){
        if(!root) return;
        m[root->val]++;
        if(!root->left && !root->right){
            int odd = 0;
            for(auto &i : m){
                if(i.second%2 == 1) odd++;
            }
            if(odd<=1) ans++;
            m[root->val]--;
            return;
        }
        preOrder(root->left,m);
        preOrder(root->right,m);
        m[root->val]--;
    }
};