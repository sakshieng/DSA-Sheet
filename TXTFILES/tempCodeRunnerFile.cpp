#include <bits/stdc++.h>
// // sakshi codes here
// using namespace std;
// #define ll long long
// #define mod (int)(1e9 + 7)
// void solve()
// {
//     string s;
//     cin >> s;
//     for (int i = 0; i < s.size() - 1; i++)
//     {
//         if (s[i] == s[i + 1])
//         {
//             for (auto ch = 's'; ch <= 'z'; ++ch)
//             {
//                 if (ch != s[i])
//                 {
//                     s.insert(s.begin() + i + 1, ch);
//                     cout << s << endl;
//                     return;
//                 }
//             }
//         }
//     }
//     for (auto ch = 's'; ch <= 'z'; ++ch)
//     {
//         if (ch != s[0])
//         {
//             cout << ch + s << endl;
//             return;
//         }
//     }
//     for (auto ch = 's'; ch <= 'z'; ++ch)
//     {
//         if (ch != s[s.size() - 1])
//         {
//             cout << s + ch << endl;
//             return;
//         }
//     }
// }

// int main()
// {
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }