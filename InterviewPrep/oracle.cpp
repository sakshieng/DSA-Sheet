// oncampus test
/*
file:///C:/Users/saksh/Downloads/IMG-20240828-WA0022.jpg
2 types of logs
[1,p,x] -> change to x
[2,-1,x] -> all microserives whose no of pods < x are changed to x
i/p:
n = 4
a = [2,4,1,4]
m = 3
logs = [[1,2,30],
        [1,3,4],
        [2,-1,10]]
o/p: [10,30,10,10]

log -> [1,2,30] 2nd member's pod cnt changed to 30 ->res pod [2,30,1,4]
log -> [1,3,4] 3rd member's pod cnt changed to 4 -> res pod [2,30,4,4]
log -> [2,-1,10] all micropods with fewer than 10 pods are changed to 10 -> res pod [10,30,10,10]

i^th elmt -> final pod cnt of i^th microservice
*/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void solve()
{
    int n;
    cin >> n;
    vector<int> pods(n);
    for (int i = 0; i < n; i++)
        cin >> pods[i];
    int m;
    cin >> m;
    vector<vector<int>> logs(m, vector<int>(3));
    // logs means queries to be performed
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> logs[i][j];
    }
    int time = 0;
    vector<int> lastUpdated(n, 0);
    vector<int> segments(m, 0);
    for (auto &q : logs)
    {
        int q[0] = first, q[1] = second, q[2] = third;
        if (first == 1)
        {
            pods[second - 1] = third;
            lastUpdated[second - 1] = time; // jithe update kelay toh idx store
        }
        else
        {
            // query of type 2
            segments[time] = third; // third means x all <x are changed to x
        }
        time++;
    }
    // this is for 2nd type of query to track max val of all segments
    // segment[m-1] = 10 as 3rd log change all < 10 to 10
    vector<int> suff(m, 0);
    suff[m - 1] = segments[m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        suff[i] = max(suff[i + 1], segments[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int myLast = lastUpdated[i];
        if (myLast + 1 <= m)
            pods[i] = max(pods[i], suff[myLast + 1]);
    }
    for (auto &i : pods)
        cout << i << " ";
    cout << "\n";
    return;
}

// bubble sort oracle on campus interview
void sortFunc()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}