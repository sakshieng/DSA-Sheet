#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/contest/weekly-contest-358/problems/double-a-number-represented-as-a-linked-list/
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
    ListNode *add(ListNode *one, ListNode *two)
    {
        ListNode *res = NULL;
        ListNode *temp, *prev = NULL;
        int tmp = 0, sum;

        while (one != NULL || two != NULL)
        {
            sum = tmp + (one ? one->val : 0) + (two ? two->val : 0);
            tmp = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            temp = new ListNode(sum);
            if (res == NULL)
                res = temp;
            else
                prev->next = temp;
            prev = temp;
            if (one)
                one = one->next;
            if (two)
                two = two->next;
        }
        if (tmp > 0)
            temp->next = new ListNode(tmp);
        return res;
    }
    ListNode *reverse_it(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *doubleIt(ListNode *head)
    {
        ListNode *l1 = NULL;
        l1 = reverse_it(head);
        ListNode *sum = reverse_it(add(l1, l1));
        return sum;
    }
};