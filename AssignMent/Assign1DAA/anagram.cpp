#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// Q) Write a method to sort an array of string so that all the anagrams are next to each other.

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &a)
    {
        // anagrams of each other should be adjacent
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < a.size(); ++i)
        {
            string s = a[i];
            sort(s.begin(), s.end());
            mp[s].push_back(a[i]);
        }
        vector<vector<string>> ans(mp.size());
        int idx = 0;
        for (auto x : mp)
        {
            auto v = x.second;
            for (int i = 0; i < v.size(); ++i)
            {
                ans[idx].push_back(v[i]);
            }
            idx++;
        }
        return ans;
    }
};
//TC -> O(n*mlog(m)) where n=size of arr m=maxi length str in array
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
            cout.flush();
        }
    }
    return 0;
}
