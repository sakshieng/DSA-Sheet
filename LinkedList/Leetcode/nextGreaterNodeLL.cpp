// https://leetcode.com/problems/next-greater-node-in-linked-list/description/
#include <bits/stdc++.h>
// reverse LL see st.top() then store the result into vector and return the reversed ans
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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL,*curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int>ans;
        stack<int>st;
        head = reverseLL(head);
        while(head){
            if(st.empty()){
                ans.push_back(0);
                st.push(head->val);
                head = head->next;
            }else if(st.top() > head->val){
                ans.push_back(st.top());
                st.push(head->val);
                head = head->next;
            }else st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};