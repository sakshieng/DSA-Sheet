#include<bits/stdc++.h>
//https://leetcode.com/problems/reverse-linked-list-ii/?envType=daily-question&envId=2023-09-07
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        //by using 2 pointers
        if(!head or left==right) return head;
        for(int i=0;i<left-1;++i) prev = prev->next;
        ListNode* curr = prev->next;
        for(int i=0;i<right-left;++i){
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode; 
        }
        return dummy.next;
    }
};