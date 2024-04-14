#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://www.hackerearth.com/de/problem/algorithm/the-monk-and-class-marks/
// make vector of string as well but here we will need sorting :: use set of string as always sorted

/* for avoiding combi of same mark same name student use mutisets u could try this by sets u will get  wrong ans for:
4
Eve 78
Bob 99
Alice 78
Alice 78
as 2 alice will combine to avoid copy
*/
int main()
{
    map<int, multiset<string>> marks_map;
    // names as sets alice before eve keep key as values in int
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int marks;
        string name;
        cin >> name >> marks;
        // marks decreasing and if marks same then names increasing order
        marks_map[marks].insert(name);
    }
    auto current_it = (--marks_map.end());
    // reverse iterate map as first element khalun max mark cha asnar
    while (true)
    {
        auto &students = (*current_it).second;
        // proceed current_it by collecting students and marks
        int marks = (*current_it).first;
        for (auto &student : students)
        {
            cout << student << " " << marks << endl;
        }
        // as reverse traverse map
        if (current_it == marks_map.begin())
            break;
        current_it--;
    }
    return 0;
}