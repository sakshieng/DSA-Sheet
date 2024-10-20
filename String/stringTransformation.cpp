#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/string-transformation_630421?leftPanelTab=0
#include <bits/stdc++.h>

string getTransformedString(string str, int k)
{
    // so the appraoch is we have to sort the string in length of k so what we will do take minHeap pop elmt add it to the str
    priority_queue<char, vector<char>, greater<char>> pq;
    string ans = "";
    int n = str.size();
    int x = min(k, n);
    for (int i = 0; i < x; ++i)
    {
        pq.push(str[i]);
    }
    // remaining str away from k
    for (int i = k; i < n; ++i)
    {
        ans += pq.top();
        pq.pop();
        pq.push(str[i]);
    }
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}
