// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2023-11-02
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
class Solution
{
public:
    int matchingSubtreeCount = 0;
    pair<int, int> calculateSubtreeValues(TreeNode *currentNode)
    {
        if (currentNode == nullptr)
            return {0, 0}; 
        auto leftSubtree = calculateSubtreeValues(currentNode->left);
        auto rightSubtree = calculateSubtreeValues(currentNode->right);

        int sumOfValues = leftSubtree.first + rightSubtree.first + currentNode->val;
        int numberOfNodes = leftSubtree.second + rightSubtree.second + 1;

        if (sumOfValues / numberOfNodes == currentNode->val)
            matchingSubtreeCount++;

        return {sumOfValues, numberOfNodes}; // for curr subtree
    }

    int averageOfSubtree(TreeNode *root)
    {
        calculateSubtreeValues(root); 
        return matchingSubtreeCount;
    }
};