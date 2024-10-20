#include <bits/stdc++.h>
using namespace std;
// Circular Linked List
class node
{
private:
    int data;
    node *next;

public:
    node() {};
    node *to_empty(node *head, int data);
};

node *node::to_empty(node *head, int new_data)
{
    if (!head)
        return head;
    node *newNode = new node();
    newNode->data = new_data;
    head = newNode;
}

// node *node::insertList(node* head,)

