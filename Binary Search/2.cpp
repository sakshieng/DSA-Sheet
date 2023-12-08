#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// LOWER BOUND

// if element is present in vector v then tyach element cha ind or just greater element cha ind
int lower_bound(vector<int> &v, int element)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < element)
        {
            lo = mid + 1;
            // if that element exists this cant be lower bound as it is less than element ::remove from search place hence +1
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] >= element)
    {
        return lo;
    }

    if (v[hi] >= element)
    {
        return hi;
    }
    return -1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int element;
    cin >> element;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    // sort(v.begin(),v.end());
    int lb = lower_bound(v, element);
    cout << lb << " " << v[lb] << endl;
    return 0;
}
