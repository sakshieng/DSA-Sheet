#include <bits/stdc++.h>
// sakshi codes here
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
    int ans = 0;
    int countPairs(TreeNode *root, int distance)
    {
        //dfs   
        dfs(root, distance);
        return ans;
    }
    vector<int>dfs(TreeNode *root, int distance)
    {
        vector<int>res;
        if(root==NULL)
            return res;
        auto left = dfs(root->left, distance);  
        auto right = dfs(root->right, distance);
        if(left.size()==0 && right.size()==0)
        {
            res.push_back(1);
            return res;
        }
        for(auto l:left)
            for(auto r:right)
                if(l+r<=distance)
                    ans++;
        for(int i=0;i<left.size();i++)
            res.push_back(left[i]+1);{
        }
        for (int i = 0; i < right.size(); i++){
            res.push_back(right[i] + 1);
        }
        return res;
    }
     
};
