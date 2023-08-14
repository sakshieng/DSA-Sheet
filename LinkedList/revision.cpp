#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
class listNode
{
private:
    int data;
    listNode *next;
public:
    listNode(){};
    listNode(int new_data)
    {
        data = new_data;
    }
    listNode(int new_data, listNode *node)
    {
        data = new_data;
        next = node;
    }
    void createNode(listNode *Next, int new_data);
    void insertAfter(listNode *head, listNode *node, int new_data);
    void reverse(listNode *head);
};

void listNode::createNode(listNode *Next, int new_data)
{
    // method 1 using empty constructor
    // listNode* head=new listNode();
    // head->data=new_data;
    // head->next=Next;

    // method 2 using 2nd constructor
    // listNode* head=new listNode(new_data);
    // head->next=Next;

    // method 3 using 3rd constructor
    listNode *head = new listNode(new_data, Next);
}
void listNode::insertAfter(listNode *head, listNode *node, int new_data)
{
    listNode *curr = new listNode(new_data);
    curr->next = node->next;
    node->next = curr;
}
void listNode::reverse(listNode *head)
{
    listNode *curr = head;
    listNode *prev = NULL, *nxt = NULL;
    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}
int main()
{
    return 0;
}
/*
 1 3 5
 4
*/