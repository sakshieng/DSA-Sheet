#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// nesting in maps and sets
/*
we want to take input of:
 3
 a b 4
 1 2 3 4
 c d 3
 1 2 5
 d f 5
 1 5 8 9 6
*/
int main()
{

    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        // fn-->first name,ln-->last name
        int cnt;
        string fn, ln;
        cin >> fn >> ln >> cnt;
        for (int j = 0; j < cnt; ++j)
        {
            // we are taking input of 1 2 3 4
            int x;
            cin >> x;
            // map ke key mai pair daalna hai
            m[{fn, ln}].push_back(x);
            // pair.first() is key of map
        }
    }
    for (auto pr : m)
    {
        // full_name is fn+ln
        auto &full_name = pr.first;
        auto &list = pr.second;
        // pr.first pr.second are vectors
        cout << full_name.first << " " << full_name.second << endl;
        cout << list.size() << endl;
        // for printing list
        for (auto &element : list)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}