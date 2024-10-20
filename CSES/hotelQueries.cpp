// https://cses.fi/problemset/task/1143
// Find the first idx i such that ri >= hi
// brute force O(log^2 N)
// by seg tree O(log N)
//assume ans is in range [l,r] 
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
const int MAXN = 200001;

int n;
int segtree[4 * MAXN], a[MAXN];

void build(int left = 1,int right = n,int node = 1){
    if(left == right)
        segtree[node] = a[left];
    else{
        int mid = (left + right)/2;
        build(left,mid,node*2);
        build(mid + 1,right,node*2 + 1);
        segtree[node] = max(segtree[node*2],segtree[node*2+1]);
    }
}
void queryUpdate(int val,int left = 1,int right = n,int node = 1){
    if(left == right)
    {
        segtree[node] -= val;
        cout << left << " ";
    }else{
        int mid = (left + right)/ 2;
        if(segtree[node*2] >= val)
            queryUpdate(val,left,mid,node*2);
        else
            queryUpdate(val,mid + 1,right,node*2 + 1);
        segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
	cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build();
    while (q--)
    {
        int x;cin >> x;
        if(segtree[1] < x)
            cout << "0 ";
        else 
            queryUpdate(x);
    }
    return 0;
}