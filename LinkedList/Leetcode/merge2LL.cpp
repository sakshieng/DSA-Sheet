#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *findMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    ListNode *ans = new ListNode(-1); // dummy ListNode
    ListNode *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *result = merge(list1, list2);
        return result;
    }
};
