
#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node *temp = NULL; 
     Node *current = head;
      
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;             
       current = current->prev;
     }     
      
     if(temp != NULL )
        head = temp->prev;
     return head;
    }
};

