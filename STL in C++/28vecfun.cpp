#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int min = *min_element(v.begin(), v.end());
    cout << min << endl;

    int max = *max_element(v.begin(), v.end());
    cout << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    // initialize to sum=0 in 3rd argument
    cout << sum << endl;

    int ct = count(v.begin(), v.end(), 2);
    cout << ct << endl;

    auto it = find(v.begin(), v.end(), 10);
    if (it != v.end())
    // for array if(it != v+n)
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Element not found\n";
    }
    reverse(v.begin(), v.end());
    for (auto val : v)
    {
        // print reverse vector
        cout << val << " ";
    }
    string s="absjsuwwjjfgk";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    cout << endl;
    return 0;
}