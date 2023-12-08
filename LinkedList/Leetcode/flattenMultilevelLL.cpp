#include <bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
Node *merge2LL(Node* a,Node* b){
    Node *tmp = new Node(0);
    Node *res = tmp;
    while (a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            tmp->child = a;
            tmp = tmp->child;
            a = a->child; 
        }else{
            tmp->child = b;
            tmp = tmp->child;
            b = b->child;
        }
    }
    if(a)
        tmp->child = a;
    else 
        tmp->child = b;
    return res->child;
    
}
Node *flattenLinkedList(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    //recur for list on right
    head->next = flattenLinkedList(head->next);
    //now merge
    head = merge2LL(head,head->next);
    //it will in turn merged with its left
    return head;
}
