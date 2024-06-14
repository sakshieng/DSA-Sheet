//we need to create binary tree where each leaf node represents a character and its frequency
//and each internal node represents sum of frequencies of its children

#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

//https://www.geeksforgeeks.org/problems/huffman-encoding3345/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// https://www.geeksforgeeks.org/problems/huffman-decoding-1/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
struct Node
{
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(Node *left,Node *right){
        return (left->freq > right->freq);
    }
};

vector<string> huffmanCodes(string s,vector<int> f,int N)
{
    struct Node *left,*right,*top;
    priority_queue<Node*,vector<Node*>,compare>pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(new Node(s[i],f[i]));
    }
    while (pq.size() != 1)//final node is root of Huffman tree
    {
        //extract 2 min freq from min heap
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        //create a new internal node with freq = sum of freq of left and right
        top = new Node('$',left->freq + right->freq);//add $ to distinguish internal node from leaf node
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    vector<string> ans;
    string str = "";
    //traverse the tree top to bottom
    //assign 0 to left edge and 1 to right edge
    //store the code in a vector
    function<void(Node*,string)> encode = [&](Node* root,string str){
        if(!root) return;
        if(root->data != '$'){//leaf node
            ans.push_back(str);
        }
        encode(root->left,str + "0");
        encode(root->right,str + "1");
    };
    encode(top,str);
    return ans;
}

