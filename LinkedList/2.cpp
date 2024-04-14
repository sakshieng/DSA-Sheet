#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(){};
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void print_list(node *n)
{
    while (n->next->next != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void push(node **head_ref, int new_data) // adding new node at the begining
{
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void insert_after(node *prev_node, int new_data) // inserting after a node
{
    if (prev_node == NULL)
    {
        cout << "GIVEN PREVIOUS NOTE CANT BE NULL";
        return;
    }
    node *new_node = new node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void _insert(node *head, int index, int new_data) // inserting at an index
{
    node *new_node = new node();
    node *p = head;
    node *q;
    ll k = 0;
    if (index == 1)
    {
        push(&p, new_data);
    }
    else
    {
        while (p != NULL && k < index)
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = new_node;
        new_node->data = new_data;
        new_node->next = p;
    }
}

void append(node **head_ref, int new_data) // inserting at the end
{
    node *n = new node();
    node *temp = *head_ref;
    n->data = new_data;
    n->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    return;
}

int main()
{
    node *head;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    print_list(head);
    _insert(head, 4, 10);
    print_list(head);
    return 0;
}
int length(node *head)
{
    node *m = new node();
    m = head;
    int lengt = 0;
    while (m != NULL)
    {
        m = m->next;
        lengt++;
    }
    return lengt;
}
int mini(node *head)

{
    node *current = new node();
    current = head;
    int mini = INT_MAX;
    while (current != NULL)

    {
        mini = min(mini, current->data);
        current = current->next;
    }
    return mini;
}
int maxi(node *head)

{
    node *current = new node();
    current = head;
    int maxi = INT_MIN;
    while (current != NULL)

    {
        maxi = max(maxi, current->data);
        current = current->next;
    }
    return maxi;
}
int sum(node *head)
{
    node *current = new node();
    current = head;
    int sum = 0;
    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
int middle_element(node *head)
{
    int leng = length(head);
    int middle = leng / 2;
    node *current = head;
    while (middle--)
    {
        current = current->next;
    }
    return current->data;
}
node *del_index(node *head, int ind)
{
    node *current = new node();
    node *prev = new node();
    current = head;
    prev = NULL;
    while (ind--)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    return head;
}
