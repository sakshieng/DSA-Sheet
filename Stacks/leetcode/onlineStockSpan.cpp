#include <bits/stdc++.h>
//https://leetcode.com/problems/online-stock-span/
using namespace std;

class StockSpanner
{
public:
    // return max possible consecutive day
    StockSpanner()
    {
    }

    int next(int price)
    {
        int curSpan = 1;
        while (st.size() && st.back().first <= price)
        {
            curSpan += st.back().second;
            st.pop_back();
        }
        st.push_back({price, curSpan});
        return curSpan;
    }

private:
    vector<pair<int, int>> st;
};
