// https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);         
        int length = 0;
        ListNode* tmp = head;
        while (tmp) { 
            length++;
            tmp = tmp->next;
        }

        int part = length / k;    
        int extra = length % k; 
        
        tmp = head; 
        ListNode* prev = nullptr;
        
        for (int i = 0; i < k; ++i) {
            ans[i] = tmp;  
            int remainder = part + (extra > 0 ? 1 : 0);
            extra--;
            
            for (int j = 0; j < remainder; ++j) {
                prev = tmp;
                tmp = tmp->next;
            }
            //Break  current part from rest of  list
            if (prev) {
                prev->next = nullptr; 
            }
        }
        
        return ans;
    }
};