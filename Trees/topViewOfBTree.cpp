#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/top-view-of-binary-tree_8230721?challengeSlug=striver-sde-challenge&leftPanelTab=1
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
/*
map
2->7
-2->4
1->3
-1->2
0->1
queue
6 -1
7 2
5 0
4 2
3 1
2 1
1 0
tree is draw a line with root at 0 and left line-1 and right as line+1 level
          1
    2           3
4       5     N     7
     6     N
the first value in map is with -2 then -1 0 1 2
so ans is
4 2 1 3 7
*/
vector<int> getTopView(TreeNode<int> *root)
{
    // map->(line,node)
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line = it.second;
        // if not present in map we are visting that node first time so initialize that node in map
        if (mp.find(line) == mp.end())
            mp[line] = node->val;

        if (node->left != NULL)
            q.push({node->left, line - 1});

        if (node->right != NULL)
            q.push({node->right, line + 1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
// TC->O(n) SC->O(n)