#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   class Solution {
public:
// LINKED LIST CYCLE
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];//moving by 1
            fast=nums[nums[fast]];//moving by 2
        }while(slow!=fast);
        fast=nums[0];
        // again keep fast at head then compare
        while (slow!=fast)
        // when they are not equal assign index to slow and fast
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
        // or return slow;
    }
};
   return 0;
}
//         this problem could be solved by freqn array but condn given is solve the problem without modifying the array and uses only constant extra space means use of container like map/stack is not allowed
//so approach is to use LINKED LIST CYCLE -->TORTOISE ALGO
  /*1 3 4 2 2
    0 1 2 3 4
    s
    f
    1 3 4 2 2
      s
         f
    1 3 4 2 2 
        s
             f
as
initially
 slow=nums[0]-->slow=1
   fast=nums[0]-->fast=1
  entered in loop
  slow=nums[1]=3
  fast=nums[nums[1]]=nums[3]=2 
    */

