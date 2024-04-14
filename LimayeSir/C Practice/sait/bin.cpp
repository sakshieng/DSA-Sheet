#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// BINARY SEARCH
// it applies to monotonic func(which maintains to given order)
// it applies to predicate fun(either return tru or false) like-->T T T T F F F F F F F
// linear search-->TC-->O(n)
int main()
{
    int n;
    // just try to understand when to terminate the search place for an element
    // lo=low index,hi=high index
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int to_find;
    cin >> to_find;
    int lo = 0, hi = n - 1;
    // in each time search space reduced by half
    while (hi - lo > 1)
    {
        int mid = lo+(hi - lo) / 2;
        sort(v.begin(),v.end());
        if (v[mid] < to_find)
        {
            // right part exist 
            lo = mid + 1;
        }
        else
        {
            // left part exist
            hi = mid;
            // as here >= came :: no mid-1
        }
    }
    // TC-->log (n) to the base 2
    if (v[lo] == to_find)
    {
        cout << lo << endl;
    }
    else
    {
        if (v[hi] == to_find)
        {
            cout << hi << endl;
        }
        else
        {
            cout << "Not found";    
        }
    }
    return 0;
}
// while(p!=NULL) while(p)