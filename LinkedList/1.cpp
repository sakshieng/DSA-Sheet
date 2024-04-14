#include <iostream>
#define ll long long int
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(){};
    // constructor of class
    // func call and class call
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// node *sakshi = new node();
// sakshi->data = 4
// node *sakshi = new node(4);
void print_list(node *n)
{
    while (n != NULL)
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
    new_node->next = prev_node->next; // 4 6 5(new node) should point to 6 4 to 5
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
    // as head cant be removed
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
        // next next jat rahne
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