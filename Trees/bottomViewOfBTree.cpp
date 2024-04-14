#include <bits/stdc++.h>
using namespace std;
// recursive logic will not work we have to keep height as bottom wala node always first thevycha
//  https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_8230745?challengeSlug=striver-sde-challenge&leftPanelTab=1
template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
/*
map(line,node)
1 9
2 7
-2 4
1 3 
-1 2 ovewritten by -1 8
0 1 by 0 5 by 0 6 as 6 is the rightmost we have to take that
queue
9 1
8 -1
7 2
6 0
5 0
4 -2
3 1
2 -1
1 0
o/p is
4 8 6 9 7
levelorder traversal extension
*/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,int>mp;
    queue<pair<BinaryTreeNode<int> *,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> * node = it.first;
        int line = it.second;
        mp[line] = node->data;//direct overwrite so no check if visited or not
        if (node->left != NULL)
            q.push({node->left, line - 1});

        if (node->right != NULL)
            q.push({node->right, line + 1}); 
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
