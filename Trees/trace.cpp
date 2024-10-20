// https://leetcode.com/discuss/interview-question/1558968/google-l4-phone-binary-tree-question
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findLCA(TreeNode* root,int a,int b){
    if(!root || root->val == a || root->val == b)
        return root;
    TreeNode* left = findLCA(root->left,a,b);
    TreeNode* right = findLCA(root->right,a,b);
    if(left != nullptr && right != nullptr)
        return root;
    if(left != nullptr)
        return left;
    else 
        return right;
}
//would tell if path exists between LCA to target
bool tracePath(TreeNode* root,int target,vector<string>&path)
{
    if(!root)
        return 0;
    if(root->val == target)
        return 1;
    path.push_back("LEFT");
    if(tracePath(root->left,target,path))
        return 1;
    path.pop_back();

    path.push_back("RIGHT");
    if(tracePath(root->right,target,path))
        return 1;
    path.pop_back();

    return 0;
}
//would generate path from a to b
vector<string>solve(TreeNode* root,int a,int b){
    TreeNode* lca = findLCA(root,a,b);
    vector<string>lcatoA,lcatoB;
    tracePath(root,a,lcatoA);
    tracePath(root,b,lcatoB);
    for (string& step : pathFromLCAtoA) step = "UP";

    // Concatenate paths
    vector<string> result = pathFromLCAtoA;
    result.insert(result.end(), lcatoA.begin(), lcatoB.end());

    return result;
}