#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)
#define take(n) \
    int n;      \
    cin >> n
#define pb push_back
#define ppb pop_back
#define len(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define nl "\n"
#define NO cout << "NO" << nl
#define YES cout << "YES" << nl
#define ull unsigned long long
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sortv(v) sort(v.begin(), v.end())
#define sorta(a, n) sort(a, a + n)
#define print(v, n)             \
    for (int i = 0; i < n; i++) \
    cout << v[i] << " "
int parent[100007];
int _rank[100007]; // number of elements in each set;
void initialise(int n)
{
    loop(i, 1, n + 1)
    {
        parent[i] = i;
        _rank[i] = 1;
    }
}

int find(int a)
{

    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}
void union_by_rank(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) // they are in same set so no need to merge
        return;
    if (_rank[a] > _rank[b]) // applying union by rank on dsu
    {
        parent[b] = a;
        _rank[a] += _rank[b]; // adding the number of elements of set B to set A
    }
    else
    {
        parent[a] = b;
        _rank[b] += _rank[a];
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    initialise(n); // initialsing the parent and rank array
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        union_by_rank(i, j);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)

    {

        if (parent[i] == i)

            cnt++;
    }
    cout << cnt << nl;
}
