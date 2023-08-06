// #include <bits/stdc++.h>
// using namespace std;

// #define sim template <class c
// #define ris return *this
// #define dor > debug &operator<<
// #define eni(x)                                                                 \
//     sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(  \
//               c i) {
// sim > struct rge { c b, e; };
// sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
// sim > auto dud(c *x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug {
// #ifdef LOCAL
//     ~debug() { cerr << endl; }
//     eni(!=) cerr << boolalpha << i;
//     ris;
// } eni(==) ris << range(begin(i), end(i));
// }
// sim, class b dor(pair<b, c> d) {
//     ris << "(" << d.first << ", " << d.second << ")";
// }
// sim dor(rge<c> d) {
//     *this << "[";
//     for (auto it = d.b; it != d.e; ++it)
//         *this << ", " + 2 * (it == d.b) << *it;
//     ris << "]";
// }
// #else
//     sim dor(const c &) { ris; }
// #endif
// }
// ;
// #define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// #define ll long long
// #define vi vector<int>
// #define pii pair<int, int>
// #define f first
// #define s second
// #define pb push_back
// #define sz(x) (int)x.size()
// #define all(x) x.begin(), x.end()

// template <typename T, typename U>
// istream &operator>>(istream &istream, pair<T, U> &p) {
//     return (istream >> p.first >> p.second);
// }

// template <typename T> istream &operator>>(istream &istream, vector<T> &v) {
//     for (auto &it : v)
//         cin >> it;
//     return istream;
// }

// template <typename T> bool amax(T &a, const T &b) {
//     return a < b ? a = b, 1 : 0;
// }
// template <typename T> bool amin(T &a, const T &b) {
//     return b < a ? a = b, 1 : 0;
// }

// const int INF = 1e9;
// const int MOD = 1e9 + 7;

// void test_case() {
//     int n;
//     cin >> n;
//     vi a(n);
//     cin >> a;

//     int mx = a[0], mn = a[0];
//     for (int i = 1; i < n; ++i) {
//         if (a[i] < mx and a[i] > mn) {
//             cout << "NO\n";
//             return;
//         }
//         amax(mx, a[i]);
//         amin(mn, a[i]);
//     }
//     cout << "YES\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//         test_case();
// }
// https://www.codechef.com/problems/MINORMAX