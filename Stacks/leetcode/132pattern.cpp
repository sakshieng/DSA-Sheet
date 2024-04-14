#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/submissions/detail/776898204/
//check out the second solution using set
int main()
{
      class Solution
      {
      public:
            bool find132pattern(vector<int> &nums)
            {
                  //         subarray->continuous subsequence-->mdhle element gayab chlatat
                  int n = nums.size();
                  stack<pair<int, int>> st;
                  //       in stack we have to push pair
                  int mini = nums[0];
                  //       we have declared mini as nums[0] as we dont know what it is
                  st.push({nums[0], mini});
                  //       as we have to push something pair so mini.mini
                  for (int i = 0; i < n; ++i)
                  {
                        while (!st.empty() && st.top().first <= nums[i])
                              st.pop();
                        if (!st.empty() && st.top().second < nums[i])
                              return true;
                        st.push({nums[i], mini});
                        mini = min(mini, nums[i]);
                  }
                  return false;
            }
      };

      /*
      we need sequence
      num1 num3 num2
      as
      num3>num2>num1

      push pair in stack of
      num3 num1

      assume x

      NSR x
      for NSR we havent reversed it becauz in map all elements go in sorted order
      if x>st.top.second then return true
      i.e.it says x is nums3 peksha motha ani nums1 peksha lahan


      here
      st.top().first=nums3
      st.top().second=nums1
      nums[i]=nums2

      if
      1 3 0 2
      nums1=1
      mums2=3
      nums3=2
      and check accordingly
       It want us to find three numbers, let's name them i, j, k, such thatj>k>i.
      To achieve that, we can maintain a monotonically decreasing stack.
      Why decreasing?
      Well, if we will have a decreasing stack, we would have two numbers,j and k, and our task will reduce to finding an i such that i<k<j, and its in the left of j. Our stack will always ensure that j>k and k is in the right of j.
      To find a suitable i, what we can do is we can have a prefix array, that stores the minimum element on the left so far. Now having that data with us, in each iteration, we can now check if our stack has some elements, and if it does, we check if the prefix (minimum_so_far) element is smaller than stack top, ie k. If we get that, we return true.

      */
      return 0;
}