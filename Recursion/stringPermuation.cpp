// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
// https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// total permutation = n! abc->abc bac cab acb bca cba

class Solution
{
public:
    // abc->abc bac cab acb bca cba

    void solve(string str, vector<string> &ans, int index)
    {
        // base case
        if (index >= str.length())
        {
            ans.push_back(str);
            return;
        }
        for (int i = index; i < str.length(); i++)
        {
            swap(str[index], str[i]);
            solve(str, ans, index + 1);
            // backtrack
            swap(str[index], str[i]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        solve(S, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for (string s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}