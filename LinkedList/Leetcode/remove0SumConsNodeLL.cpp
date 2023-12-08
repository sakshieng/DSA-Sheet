#include<bits/stdc++.h>
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//prefix sum 0 alele nodes remove kryche ahet sum->key,value of node->val
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0),*curr = dummy;
        dummy->next = head;
        map<int,ListNode*>mp;
        int sum = 0;
        while (curr != NULL)
        {
            sum += curr->val;
            if(mp.count(sum)){
                curr = mp[sum]->next;
                int p = sum + curr->val;
                while(p!=sum){
                    mp.erase(p);
                    curr = curr->next;
                    p += curr->val;
                }
                mp[sum]->next = curr->next;
            }else{
                mp[sum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};