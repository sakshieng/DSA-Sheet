#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
//https://www.codechef.com/START98D/problems/AIRM
bool comp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n],dep[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        for (int i = 0; i < n; ++i)
            cin >> dep[i];

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]]++;
            mp[dep[i]]++;
        }

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        auto a = max_element(vec.begin(), vec.end(), comp);
        cout << a->second << endl;
    }
    return 0;
}
