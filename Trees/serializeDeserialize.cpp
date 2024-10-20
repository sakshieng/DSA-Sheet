// https://leetcode.com/problems/serialize-and-deserialize-bst/
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

//General Solution for Serialize and Deserialize BST and Serialize and Deserialize BT

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  

class Codec
{
public:
    unordered_map<string, int> mp;
    vector<TreeNode *> ans;
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        string s = "";
        // level-order traversal
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            q.pop();

            if (curNode == nullptr)
            {
                s += "#,";
            }
            else
            {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        // to tokenize serialized data
        stringstream s(data);
        string str = "";
        // root value of data
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        // level order traversal
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str != "#")
            {
                // not a leaf node
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            // reading value of right child from deserailzed data
            getline(s, str, ',');
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
