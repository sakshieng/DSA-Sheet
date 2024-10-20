// https://leetcode.com/problems/reorder-list/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* p = head;
        stack<ListNode*> st;
        int len = 0;
        while (p != nullptr)
        {
            st.push(p);
            len++;
            p = p->next;
        }
        ListNode* curr = head;//curr has whole LL
        for (int i = 0; i < len/2; i++)
        {
            ListNode* prev = st.top();
            st.pop();
            prev->next = curr->next;
            curr->next = prev;
            curr = curr->next->next;
        }
        curr->next = nullptr;//to terminate modified LL   
    }
};