// C++ program to find the lexicographically smallest K-length subsequence from a given string using brute force.
#include<bits/stdc++.h>
using namespace std;
 
// to store all the possible subsequences of length K
vector<string> allSubStr;
 
// to generate all possible subsequences of length K and store them in a vector
void generate(string currStr, string inputStr, int ind, int k)
{
    if (currStr.length() == k)
    {
        allSubStr.push_back(currStr);
        return;
    }
    if (ind >= inputStr.length())
        return;
 
    // add curr character into the current string
    generate(currStr + inputStr[ind], inputStr, ind + 1, k);
 
    //  without adding the curr character into the current string
    generate(currStr, inputStr, ind + 1, k);
}
void lexicographicallySmallestSubsequence(string &s, int k)
{
    int n = s.length();
    stack<char> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty())
        {
            ans.push(s[i]);
        }
        else
        {
            // Iterating till the current char < char at  top of stack and checking if at least K characters remain in the rest of the string.
            while ((!ans.empty()) && (s[i] < ans.top()) && (ans.size() - 1 + n - i >= k))
            {
                ans.pop();
            }
 
            if (ans.empty() || ans.size() < k)
            {
                ans.push(s[i]);
            }
        }
    }
 
    string result;
 
    while (!ans.empty())
    {
        result.push_back(ans.top());
        ans.pop();
    }
 
    reverse(result.begin(), result.end());
    cout << result;
}
 
int main()
{
    string currStr, inputStr;
    int k;
 
    cout << "Enter the string: ";
    cin >> inputStr;
    cout << "Enter the value of k: ";
    cin >> k;
 
    generate(currStr, inputStr, 0, k);
 
    sort(allSubStr.begin(), allSubStr.end());
 
    cout << "lexicographically smallest k-length subsequence is ";
    cout << allSubStr[0];
    cout<<"\n";
    cout << "lexicographically smallest k-length subsequence is ";
    lexicographicallySmallestSubsequence(inputStr, k);
    return 0;
}