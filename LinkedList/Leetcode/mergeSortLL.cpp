#include <bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514?leftPanelTab=0&campaign=YouTube_CodestudioLovebabbar5thfeb
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *findMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while (fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node* merge(node* left,node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;
    node *ans = new node(-1);//dummy node
    node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next; 
        }else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next; 
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
node *mergeSort(node *head)
{
    if(head == NULL || head->next == NULL) return head;
    //divide LL in 2 halves
    node *mid = findMid(head);
    node *left = head;
    node *right = mid->next;
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    node *result = merge(left,right);
    return result;
}
