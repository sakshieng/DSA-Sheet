#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
//UPPER BOUND 



int upper_bound(vector<int> &v, int element)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        int mid=lo+(hi-lo)/2;
        if (v[mid] <= element)
        {
            lo = mid + 1;
            // we have eliminate equal to part from search place
        }
        else
        {
            hi = mid;
            // mid can be ans to ho
        }
    }
    if(v[lo] > element)
    {
        return lo;
    }
    
    if(v[hi] > element)
    {
        return hi;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int element;
    cin>>element;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    // sort(v.begin(),v.end());
    int ub=upper_bound(v ,element);
    if(ub != -1)
    {
        cout<<ub<<" "<<v[ub];
    }
    else
    {
        return -1;
    }
}