#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/submissions/detail/776694599/
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
    int pairSum(ListNode* head) {
        stack<ListNode *>st;
      ListNode *p=new ListNode();
      p=head;
      int length=0;
    //   ll given chi length
      while(p!=NULL)
      {
        st.push(p);
        // pushed nodes of LL p in stack
        p=p->next;
        length++;
      }
      int i=0;
      ListNode *q=new ListNode();
    //   created new LL for storing poped nodes
      q=head;
      int maxi=INT_MIN;
      while(i<length/2)
    //   as pairs are compared :: loop will run upto l/2
      {
        ListNode *x=st.top();
        st.pop();
        maxi=max(maxi,x->val+q->val);
        q=q->next;
        i++;
      }
      return maxi;
    }
};
   return 0;
}
/*
here we haven given n even nodes LL and we have to find 1st 4th sum is greater or less than 2nd 3rd sum
so we created stack using linked list 
insert nodes of LL to stack pop up them one by one store them to another LL and check sum
*/