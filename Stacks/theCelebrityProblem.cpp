#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void print(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}