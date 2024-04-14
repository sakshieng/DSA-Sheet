#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/unequal-adjacent-elements_1404698?leftPanelTab=0
/*
    TC: O( N * logN )
    SC: O( N )
*/

vector<int> rearrangeArray(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>> pq;
    // Insert the element and its frequency in the priority queue 'P_QUEUE'
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[i] == arr[j])
        {
            j++;
        }
        pq.push(make_pair(j - i, arr[i]));
        i = j - 1;
    }
    int prev = -1;
    int prevFreq = 0;
    vector<int> ans;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        ans.push_back(p.second);
        if (prevFreq > 0)
        {
            pq.push(make_pair(prevFreq, prev));
        }
        prevFreq = p.first - 1;
        prev = p.second;
    }
    return ans;
}