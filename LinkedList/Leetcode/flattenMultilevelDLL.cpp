#include <bits/stdc++.h>
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};
// using queue O(n) tc and sc
//recursive
class Solution
{
public:
    Node *flatten(Node *head)
    {
        if(head == nullptr)
            return head;
        Node* childNode = head->child;
        Node* nextNode = head->next;
        Node* childLast = flatten(childNode);
        Node* nextLast = flatten(nextNode);
        head->child = nullptr;
        if(childLast != nullptr)
        {
            head->next = childNode;
            childNode->prev = head;
            head = childLast;
        }
        if(nextLast != nullptr)
        {
            head->next = nextNode;
            nextNode->prev = head;
            head = nextLast;
        }
        return head;
    }
};