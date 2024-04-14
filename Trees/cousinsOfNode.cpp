// https://www.geeksforgeeks.org/problems/cousins-of-a-given-node/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int>ans;
        if(root == node_to_find)
        {
            ans.push_back(-1);
            return ans;
        }
        queue<Node*>q;
        bool flg = 0;
        int size;
        Node* p;
        q.push(root);
        while (!q.empty() && !flg)
        {
            size = q.size();
            while(size--){
                p = q.front();
                q.pop();
                if ((p->left == node_to_find || p->right == node_to_find)) {
    				flg = 1;
    			}
    			else {
    				if (p->left)
    					q.push(p->left);
    				if (p->right)
    					q.push(p->right);
    			}
    
            }
        }   
        if (flg)
    	{
    		size = q.size();
    		if (size == 0)
    			ans.push_back(-1);
    		for (int i = 0; i < size; i++) {
    			p = q.front();
    			q.pop();
    			ans.push_back(p->data);
    		}
    	}
    	else
    		ans.push_back(-1);    
    	return ans;
    }
};
