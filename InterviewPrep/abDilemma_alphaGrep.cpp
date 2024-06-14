//__gcd(a,b) == 1 means a & b are coprime
#include <bits/stdc++.h>
// sakshi codes here
// determine which divisiors are common to both
//  https://maang.in/mocks/attempts/2170?problem_id=520

using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int32_t main()
{
    fastio;
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int com = __gcd(a, b);
    set<int> p;
    for (int i = 2; i * i <= com; i++)
    {
        while (com % i == 0)
        {
            com /= i;
            p.insert(i);
        }
    }
    if (com > 1)
        p.insert(com);
    cout << p.size() + 1 << '\n';
    return 0;
}