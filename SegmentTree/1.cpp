#include <bits/stdc++.h>
using namespace std;
int m = 1e9 + 7;
//https://codeforces.com/contest/1932/problem/C
template <typename T>
class SegmentTree {
public:
    using SizeType = size_t;
 
    SizeType n;
    vector<T> tree;
    SegmentTree(SizeType _N) : n(_N), tree(_N * 4, T{}) {}
    void build(int idx,int low,int high,vector<int>& nums) {
        if(low == high) {
            tree[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
    T query(int idx,int low,int high,int l,int r) {
        if(low > r || high < l) return 0;
        if(low >= l && high <= r) return tree[idx];
        int mid = (low + high) / 2;
        return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
    }
    void update(int idx,int low,int high,int l,int r,T val){
        if(low == high){
            tree[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if(l <= mid){
            update(2 * idx + 1, low, mid, l, r, val);
        } else {
            update(2 * idx + 2, mid + 1, high, l, r, val);
        }
        tree[idx] = ((tree[2 * idx + 1] % m) * (tree[2 * idx + 2] % m)) % m;
    }
    void sg_build(vector<int>& nums) {
        build(0, 0, n - 1, nums);
    }
    T sg_query(int l,int r) {
        return query(0, 0, n - 1, l, r);
    }
    void sg_update(int l,int r,T val) {
        update(0, 0, n - 1, l, r, val);
    }
};
void solve(){
    int n; cin >> n;
    cin >> m;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    string s; cin >> s;
    SegmentTree<int> sg(n);
    sg.sg_build(a);
    int low = 0, high = n-1;
    for(int i = 0; i < n; ++i){
        cout << sg.sg_query(low, high) % m << " ";
        if(s[i] != 'L') high--;
        else low++;
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}