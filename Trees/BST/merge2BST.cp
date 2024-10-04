#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int>merge2Arr(vector<int>&a,vector<int>&b){
    int n = a.size(), m = b.size();
    vector<int>ans(n+m);
    int i = 0,j = 0,k = 0;
    while (i<n && j<m)
    {
        if(a[i] < b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }
    while (i < n)
    {
        ans[k++] = a[i++];
    }
    while (j < m)
    {
        ans[k++] = b[j++];
    }
    return ans;
}
//make a traversal on bst
void inorder(TreeNode* root,vector<int>& ans){
    if(!root)
        return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //as inorders of BST are sorted   
    vector<int>a , b;
    inorder(root1,a);
    inorder(root2,b);
    return merge2Arr(a,b); 
}