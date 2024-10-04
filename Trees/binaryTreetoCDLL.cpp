// https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1
// left pointer as prev in LL and right pointer as next in LL
#include <bits/stdc++.h>
// amazon interview que
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // for concatenation of 2 lists
    Node *solve(Node *leftList, Node *rightList)
    {
        if (!leftList)
            return rightList;
        if (!rightList)
            return leftList;
        Node *leftLast = leftList->left;
        Node *rightLast = rightList->left;
        // last node of left list with first node of right list
        leftLast->right = rightList;
        rightList->left = leftLast;

        // left of first nodes points to last node in list
        leftList->left = rightLast;
        // right of last node points to first node in list
        rightLast->right = leftList;
        return leftList;
    }
    Node *bTreeToCList(Node *root)
    {
        if (!root)
            return NULL;
        Node *left = bTreeToCList(root->left);
        Node *right = bTreeToCList(root->right);
        // for LL to be circular
        root->left = root->right = root;
        return solve(solve(left, root), right); // left with curr node and returned list with right list
    }
    bool palindrome(string s,int left,int right){
        while (left <= right)
        {
            if(s[left] != s[right]) {
                //we are shrinking the window
                left++;
                right--;
                return 0;
            }
        }
        return 1;
    }
    void func(int idx,string s,vector<vector<string>>&ans,vector<string>&path){
        //i 0 to n-1
        if(idx == s.length()){
            ans.push_back(path);
            return;
        }
        for(int i = idx;i < s.size();++i){
            if(palindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                //recursive call to the function
                func(idx+1,s,ans,path);
                path.pop_back();//backtracking to the prev idx
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        func(0,s,ans,path);
        return ans;
    }
    /*
    aab
    a|ab -> no ab is not pali
    aa|b -> yes aa & b
    idx -> start of the str ith positon such that every substr would be a pali
    */
};

