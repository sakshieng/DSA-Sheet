#include <bits/stdc++.h>
// https://leetcode.com/problems/copy-list-with-random-pointer/?envType=daily-question&envId=2023-09-05
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    // optimized code
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node *ptr = head;
        while (ptr != nullptr)
        {
            Node *newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }

        ptr = head;

        while (ptr != nullptr)
        {
            ptr->next->random = (ptr->random != nullptr) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        Node *ptrOldList = head;
        Node *ptrNewList = head->next;
        Node *head_old = head->next;
        while (ptrOldList != nullptr)
        {
            ptrOldList->next = ptrOldList->next->next;
            ptrNewList->next = (ptrNewList->next != nullptr) ? ptrNewList->next->next : nullptr;
            ptrOldList = ptrOldList->next;
            ptrNewList = ptrNewList->next;
        }
        return head_old;
    }
};

// TC O(n) SC O(1) constant space
// create copy nodes and insert immediate after origi nodes
// it->deep copy of item so it->next che random pointer = item random che next
// the motive is to get deep copy LL back and random copy LL back