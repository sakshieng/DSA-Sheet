#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/odd-even-linked-list/

// add even LL head to odd LL tail
//   we need to return head of LL so for 1 2 3 4 5 LL we also need oddHead

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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL;
        int cnt = 1;
        while (head)
        {
            if (cnt % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    // we are at 2 head and tail are 2 and move to next
                    evenHead = head;
                    evenTail = head;
                    head = head->next;
                }
                else
                {
                    // means 2->4 ase hoil
                    evenTail->next = head;
                    evenTail = evenTail->next;
                    head = head->next;
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    // we are at 1 head and tail are 1 and move to next
                    oddHead = head;
                    oddTail = head;
                    head = head->next;
                }
                else
                {
                    // means 1->3 ase hoil
                    oddTail->next = head;
                    oddTail = oddTail->next;
                    head = head->next;
                }
            }
            cnt++;
        }
        // for safe check any of them is null return other
        if (oddHead == NULL)
            return evenHead;
        if (evenHead == NULL)
            return oddHead;

        evenTail->next = NULL;    // 5 nantr khi nhi
        oddTail->next = evenHead; // 1->3->5 la 2->4 add
        return oddHead;           // 1->3->5->2->4
    }
};