// https://www.geeksforgeeks.org/problems/find-the-node-with-maximum-gcd-of-the-siblings-of-a-binary-tree/1
// https://leetcode.com/discuss/interview-question/396996/Google-or-OA-Summer-Intern-2020-or-Greatest-Common-Divisor
//two diifrent problem are written here
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    int a = 0,d = 0;
    void solve(Node *root){
        if(!root)
            return;
        solve(root->left);
        solve(root->right);
        if(root->left && root->right)
        {
            int k = __gcd(root->right->data,root->left->data);
            a = max(a,k);
            d = root->data;
        }
    }
    int maxGCD( Node* root)
    {
        a = 0,d = 0;
        solve(root);
        return d;
    }
};
//OA que ans
int main() {
    int n;
    cin >> n;

    if (n == -1) {
        // If the tree is empty
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i <= n; ++i) {
        int val;
        while (cin >> val) {
            tree[i].push_back(val);
            if (cin.peek() == '\n') break; // Read until end of line
        }
    }

    vector<int> gcdValues;

    for (int i = 0; i < tree.size(); ++i) {
        for (int j = 0; j < tree[i].size(); j += 2) {
            if (j + 1 < tree[i].size() && tree[i][j] != -1 && tree[i][j + 1] != -1) {
                gcdValues.push_back(__gcd(tree[i][j], tree[i][j + 1]));
            }
        }
    }

    if (gcdValues.empty()) {
        cout << 0 << endl;
    } else {
        int maxGCD = *max_element(gcdValues.begin(), gcdValues.end());
        int minGCD = *min_element(gcdValues.begin(), gcdValues.end());
        cout << maxGCD - minGCD << endl;
    }

    return 0;
}
