#include<bits/stdc++.h>
//https://leetcode.com/problems/reverse-nodes-in-k-group/
// https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr=dummy,*nex = dummy,*prev = dummy;
        int cnt = 0;
        while (curr->next != nullptr)
        {
            //find length of linked list
            curr = curr->next;
            cnt++;
        }
        while (cnt >= k)
        {
            //iterate over right LL
            curr = prev->next;
            nex = curr->next;
            for(int i=1;i<k;++i){//do k-1 iteration to revrse links for every grp size
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            cnt -= k;
        }
        return dummy->next;
    }
    
};