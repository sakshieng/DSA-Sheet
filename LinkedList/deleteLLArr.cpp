// https://leetcode.com/contest/weekly-contest-406/problems/delete-nodes-from-linked-list-present-in-array/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

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
    ListNode *deleteNode(ListNode *head, unordered_set<int> &st)
    {
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        ListNode *curr = tmp;
        while (curr->next != nullptr)
        {
            if (st.count(curr->next->val))
            {
                ListNode *toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            }
            else
            {
                curr = curr->next;
            }
        }
        ListNode *newH = tmp->next;
        delete tmp;
        return newH;
    }
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        return deleteNode(head, numSet);
    }
};