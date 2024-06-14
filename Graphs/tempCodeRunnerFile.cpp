#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

#define ll long long
#define mod (int)(1e9 + 7)

pair<int, int> solve(const vector<string> &arr,int n, int m)
{
    int mini = INT_MAX, maxi = INT_MIN;
    int mindiff = INT_MAX, maxdiff = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j] == '#'){
                int sum = i + j;
                int diff = i - j;
                mini = min(mini,sum);
                maxi = max(maxi,sum);
                mindiff = min(mindiff,diff);
                maxdiff = max(maxdiff,diff);
            }
        }
    }
    int a = (mini+maxi)/2;
    int b = (mindiff+maxdiff)/2;
    return {a+1,b+1};
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> grid[i];
        }
        auto center = solve(grid, n, m);
        cout << center.first << " " << center.second << endl;
    }
    return 0;
}