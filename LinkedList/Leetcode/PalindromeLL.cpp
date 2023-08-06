#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/problems/palindrome-linked-list/
int main()
{
   /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
//         first half of LL stack mdhe store krychi ani mg next sobat compare kryche
//       1 2 2 1 store 1 2 in stack then compare
//       loop upto i<n/2 ani stack mdhe nimme nodes push kryche
//       ANOTHER APPROACH IS TORTOISE ALGORITHM
      ListNode *p=head;
      ListNode *q=head;
        int length=0;
        // here int val means int data
      while(p)
      {
        length++;
        p=p->next;
      }
      int i=0;
      stack<ListNode *>st;
    //   created LL have data type ListNode *
      while(i<length/2)
      {
        // half of nodes of LL are stored in stack
        st.push(q);
        q=q->next;
        i++;
      }
      if(length%2==1) q=q->next;
    //   this is for odd no of nodes 1 0 1 ignore 0 for checking palindrome skip middle node by doing q=q->next
      while(!st.empty())
      {
        ListNode *node=st.top();
        if(node->val != q->val)
          return false;
        st.pop();
        q=q->next;
      }
      return true;
    }
};
   return 0;
}
/*
this approach requires SC-->O(n) and TC-->O(n)

as any container like maps , vectors , stack , queue requires SC-->O(n)

BEST APPROACH-->TORTOISE ALGORITHM
*/