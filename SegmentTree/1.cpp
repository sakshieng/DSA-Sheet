#include <bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, int arr[], int seg[])
{
    if (low == high)
    {
        seg[idx] = arr[idx];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, arr, seg);
    build(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int seg[4 * n];
    build(0,0,n-1,arr,seg);
    
}
int main()
{

    return 0;
}