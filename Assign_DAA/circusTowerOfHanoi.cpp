
/*
A circus is designing a tower routine consisting of people standing atop one another’s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weight of each circus, write a method to compute the largest possible number of people in such tower.
EXAMPLE:
Input(ht,wt): (65, 100) (70, 150) (56, 90) (75,190) (60, 95) (68, 110).
Output: The longest tower is length 6 and includes from top to bottom:
(56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)
*/
// sort data acc to height O(nlogn)
// sort data acc to weight O(nlogn)
// find length of LCS from d1 and d2
#include <bits/stdc++.h>
using namespace std;

bool compareByHeight(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

bool compareByWeight(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

// int LCS(vector<pair<int, int>> &height, vector<pair<int, int>> &weight)
// {
//     int n = height.size(), m = weight.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     for (int i = 1; i <= n; i++) // Change i-- to i++
//     {
//         for (int j = 1; j <= m; j++) // Change j-- to j++
//         {
//             if (height[i - 1] == weight[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[n][m];
// }

void print(vector<pair<int, int>> &data)
{
    vector<pair<int, int>> heightSorted = data;
    vector<pair<int, int>> weightSorted = data;

    sort(heightSorted.begin(), heightSorted.end(), compareByHeight);
    sort(weightSorted.begin(), weightSorted.end(), compareByWeight);



    int n = heightSorted.size();
    int m = weightSorted.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int i = n, j = m;
    vector<pair<int, int>> tower;

    while (i > 0 && j > 0)
    {
        if (heightSorted[i - 1] == weightSorted[j - 1])
        {
            tower.push_back(heightSorted[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(tower.begin(), tower.end());

    for (const auto &p : tower)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
}
int main()
{
    vector<pair<int, int>> data1 = {
        make_pair(65, 100),
        make_pair(70, 150),
        make_pair(56, 90),
        make_pair(75, 190),
        make_pair(60, 95),
        make_pair(68, 110)};

    // int result = LCS(data1, data1);
    // cout << "The longest tower is length " << result << " and includes from top to bottom:" << endl;

    print(data1);
    return 0;
}
