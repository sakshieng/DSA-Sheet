//last que
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    int count; // no of nodes in left subtree, including this node.
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int x) {
        if (!node) {
            return new TreeNode(x);
        }

        if (x <= node->val) {
            node->left = insert(node->left, x);
            node->count++; // count++ for left subtree.
        } else {
            node->right = insert(node->right, x);
        }

        return node;
    }

    int getRank(TreeNode* node, int x) {
        if (!node) {
            return 0;
        }

        if (x == node->val) {
            return node->count - (node->right ? node->right->count : 0);
        } else if (x < node->val) {
            return getRank(node->left, x);
        } else {
            return node->count + getRank(node->right, x);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void track(int x) {
        root = insert(root, x);
    }

    int getRankOfNumber(int x) {
        return getRank(root, x);
    }
};

int main() {
    BinarySearchTree bst;
    
    bst.track(5);
    bst.track(1);
    bst.track(4);
    bst.track(4);
    bst.track(5);
    bst.track(9);
    bst.track(7);
    bst.track(13);
    
    cout << "Rank of 4: " << bst.getRankOfNumber(4) << endl; // print 3 (values <= 4: 1, 4, 4)
    cout << "Rank of 9: " << bst.getRankOfNumber(9) << endl; // print 6 (values <= 9: 1, 4, 4, 5, 5, 9)

    return 0;
}
