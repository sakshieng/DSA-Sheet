// https://leetcode.com/contest/biweekly-contest-110/problems/insert-greatest-common-divisors-in-linked-list/

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
//   Definition for singly-linked list.
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
    int gcd(int a, int b)
    {
        while (b)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void insertNode(ListNode *prevs, ListNode *nexts, int gcdValue)
    {
        ListNode *newNode = new ListNode(gcdValue);
        prevs->next = newNode;
        newNode->next = nexts;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *current = head;
        while (current->next != NULL)
        {
            int gcdValue = gcd(current->val, current->next->val);
            if (gcdValue != 0)
            {
                insertNode(current, current->next, gcdValue);
                current = current->next;
            }
            current = current->next;
        }

        return head;
    }
};