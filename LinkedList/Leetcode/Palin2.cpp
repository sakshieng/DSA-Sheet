#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/problems/palindrome-linked-list/
// same problem just by TORTOISE ALGORITHM
// TC-->O(n) SC-->O(1)
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
  bool isPalindrome(ListNode *head)
  {
    if (!head || !(head->next))
      return head;
    ListNode *fast = head;
    ListNode *slow = head;
    // order of this and cond is imp
    while (fast->next != NULL && fast->next->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow = slow->next;
    slow = reverseLL(slow);
    fast = head;
    while (slow != NULL)
    {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }
    return true;
  }
  //     func to reverse LL
  ListNode *reverseLL(ListNode *curr)
  {
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

/*
1 0 0 1
s
f
1 0 0 1
  s
     f
slow=slow->next
and reverse
so
right half gets reversed
1 0 1 0
    s
f
as fast->val ==slow->val
return true
*/