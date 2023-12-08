//    https://csacademy.com/contest/interview-archive/task/all-bst-preorders/statement/
#include <bits/stdc++.h>
using namespace std;

 
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void generatePreorderTraversals(int n);

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(nullptr);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);
        vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

        for (TreeNode* left : leftSubtrees) {
            for (TreeNode* right : rightSubtrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

void preorderTraversal(TreeNode* node) {
    if (node) {
        cout << node->val << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}


void allBstPreorders(int n) {
    vector<TreeNode*> trees = generateTrees(1, n);

    for (TreeNode* tree : trees) {
        preorderTraversal(tree);
        cout << endl;
    }
}
   
int main() {
    int N;
    cin >> N;
    allBstPreorders(N);
    return 0;
}
