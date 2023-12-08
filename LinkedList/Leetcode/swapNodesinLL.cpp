#include <bits/stdc++.h>
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *left = head, *right = head;
        for (int i = 0; i < k - 1; ++i) // move the right_ptr k-2 steps forward
            right = right->next;
        ListNode *end = right;
        while (right->next != NULL)
        {
            left = left->next;
            right = right->next;
        }
        swap(end->val, left->val);
        return head;
    }
};
