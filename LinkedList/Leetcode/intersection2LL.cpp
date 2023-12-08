#include <bits/stdc++.h>
/*
Find tail -> Connect tail with any of head which creates a loop
->Using other head, find intersection point of loop
->Undo loop, by setting tail->next = NULL
->Return intersection node
*/
//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
//https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        //find tail
        ListNode* tail = headA;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = headA;//will form loop
        ListNode* fast = headB, *slow = headB;//to find intersection
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = headB;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                tail->next = NULL;//undo the loop
                return slow;
            }
        }
        tail->next = NULL;
        return NULL;
    }
};