#include <bits/stdc++.h>
//https://leetcode.com/problems/merge-k-sorted-lists/
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    // O(n*klogk) n = no of nodes in LL sc O(k)
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
        int k = lists.size();
        if (k == 0)
            return NULL;
        for (int i = 0; i < k; ++i)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (!minHeap.empty())
        {
            ListNode *top = minHeap.top();
            minHeap.pop();
            if (top->next != NULL)
            {
                minHeap.push(top->next);
            }
            if (head == NULL)
            {
                // answer LL isempty
                head = top;
                tail = top;
            }
            else
            {
                // insert at LL
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};