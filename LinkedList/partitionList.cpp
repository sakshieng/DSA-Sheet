#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *before = new ListNode(0);
        ListNode *after = new ListNode(0);
        ListNode *tmpBefore = before;
        ListNode *tmpAfter = after;
        while (head != NULL)
        {
            if (head->val < x)
            {
                tmpBefore->next = head;
                tmpBefore = head;
            }
            else
            {
                tmpAfter->next = head;
                tmpAfter = head;
            }
            head = head->next;
        }
        tmpAfter->next = NULL;
        tmpBefore->next = after->next;
        return before->next;
    }
};