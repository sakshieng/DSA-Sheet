// https://leetcode.com/problems/count-collisions-on-a-road/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    // if RL SL RS asel trch collsion
    int countCollisions(string directions)
    {
        int n = directions.size();
        stack<char16_t> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(directions[i]);
            else if (st.top() == 'S' && directions[i] == 'L')
                ans++;
            else if (st.top() == 'R' && directions[i] == 'L')
            {
                st.pop();
                directions[i] = 'S';
                i--;
                ans += 2;
            }
            else if (st.top() == 'R' && directions[i] == 'S')
            {
                st.pop();
                directions[i] = 'S';
                i--;
                ans++;
            }
            else
                st.push(directions[i]);
        }
        return ans;
    }
};