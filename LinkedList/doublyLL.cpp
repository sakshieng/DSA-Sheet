#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *prev;
};
int findLen(Node *head)
{
    int cnt = 0;
    for (Node *curr = head; curr != nullptr; curr++)
    {
        cnt++;
    }
    return cnt;
}
Node *insertBegin(Node *head, int data)
{
    Node *tmp = new Node(data);
    tmp->next = head;
    if (!head)
        head->prev = tmp;
    return tmp;
}
Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
        return temp;

    Node *curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}
Node *delHead(Node *head)
{
    if (!head)
        return nullptr;
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    delete temp;
    return head;
}
Node *delLast(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->prev->next = NULL;
    delete curr;
    return head;
}
void printDLL(Node *head)
{
    Node *curr = new Node();
    curr = head;
    while (curr->next != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}
void forwardTraversal(Node *head)
{

    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void backwardTraversal(Node *tail)
{

    Node *curr = tail;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int main()
{
   
    return 0;
}

