#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/add-two-numbers/
//  Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head, *ans = &head;
        // dummy head create kela
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            ans->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL and l2 == NULL)
        {
            ans->next = new ListNode((l1->val + 0 + carry) % 10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            ans = ans->next;
        }
        while (l2 != NULL and l1 == NULL)
        {
            ans->next = new ListNode((0 + l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            ans = ans->next;
        }
        if (carry != NULL)
        {
            ans->next = new ListNode(carry);
        }
        // .* == ->
        return head.next;
    }
};