// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        int max = -1;
        string temp = "";
        for (auto i : m)
        {
            if (i.second > max)
            {
                max = i.second;
                temp = i.first;
            }
        }
        vector<string> ans;
        ans.push_back(temp);
        ans.push_back(to_string(max));
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
