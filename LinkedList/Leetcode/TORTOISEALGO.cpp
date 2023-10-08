/*
Proof of Floyd Cycle Chasing (Tortoise and Hare)
I am looking for a proof of Floyd's cycle chasing algorithm, also referred to as tortoise and hare algorithm. After researching a bit, I found that the proof involves modular arithmetic (which is logical since we are dealing with cycles).

I am trying to prove two things.

First, if a cycle does exist, and you advance the tortoise one node each unit of time but the hare two nodes each unit of time, then they will eventually meet.

Second, when they meet the tortoise will be nα away from the start of the sequence (where α is the loop length) and also nα away from the hare.

DISCUSSION MUST READ-->
https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
*/
#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/problems/linked-list-cycle/

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == NULL)
      return false;
    ListNode *fast = head;
    ListNode *slow = head;
    // till fast and fast-> next not reaches NULL
    // we will increment fast by 2 step and slow by 1 step
    while (fast != NULL && fast->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;

      // At the point if fast and slow are at same address
      // this means linked list has a cycle in it.
      if (fast == slow)
        return true;
    }
    // if traversal reaches to NULL this means no cycle.
    return false;
  }
};
/*
3 2 0 -4
3-->starting head
2-->entry node
-4-->meeting head

3 | 2 0 -4<--cycle is of 3 nodes
s
f
3 2 0 -4
  s
    f
3 2 0 -4
    s
  f
3 2 0 -4
       s
       f
as slow fast encounters -4 is meeting point to find entry count head++ and slow++
for this problem we have to consider how many nodes are before entry point(2) as final ans changes acc
we have to baiscally return it is valid linked list or not

Linked List Cycle looks like
1-->2-->3
    ↑    |
    |    ↓
    5  <-4
  TC-->O(n)
  SC-->O(1)
*/