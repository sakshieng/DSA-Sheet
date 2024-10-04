// https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        Node *res = nullptr;
        Node *tmp;
        while (node1 != nullptr && node2 != nullptr)
        {
            if (node1->data <= node2->data)
            {
                tmp = node1->next;
                node1->next = res;
                res = node1;
                node1 = tmp;
            }
            else
            {
                tmp = node2->next;
                node2->next = res;
                res = node2;
                node2 = tmp;
            }
        }
        while (node1 != NULL)
        {
            Node *temp = node1->next;
            node1->next = res;
            res = node1;
            node1 = temp;
        }

        while (node2 != NULL)
        {
            Node *temp = node2->next;
            node2->next = res;
            res = node2;
            node2 = temp;
        }
        return res;
    }
};