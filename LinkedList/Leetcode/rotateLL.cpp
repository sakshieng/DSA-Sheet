#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://www.naukri.com/code360/problems/rotate-linked-list_920454?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries&leftPanelTabValue=PROBLEM
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *findNthNode(Node *temp, int k)
{
    int cnt = 1;
    while (temp != NULL)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotate(Node *head, int k)
{
    if (head == nullptr || k == 0)
        return head;
    Node *tail = head;
    int len = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        len += 1;
    }
    if (k % len == 0)
        return head;
    k = k % len;
    // attach the tail to the head
    tail->next = head;
    Node *newLastNode = findNthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}
