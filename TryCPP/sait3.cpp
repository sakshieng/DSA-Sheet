#include <bits/stdc++.h>
using namespace std;

void finalPosition(string move)
{
    int l = move.size();
    int up = 0, down = 0;
    int left = 0, right = 0;
    bool flg = false;
    for (int i = 0; i < l; i++)
    {
        // For each movement increment its
        // respective counter
        if (move[i] == 'U')
            up++;
        else if (move[i] == 'D')
            down++;
        else if (move[i] == 'L')
            left++;
        else if (move[i] == 'R')
            right++;
    }
    // we want pos to check if robot is at pos (1,1)
    if ((right - left) == 1 && (up - down) == 1)
    {
        flg = true;
    }
    if (flg)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        finalPosition(s);
    }
    return 0;
}
