#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int>& ans) {
    int n = ans.size();
    sort(ans.rbegin(), ans.rend()); 

    vector<int> b, c;
    b.push_back(ans[0]);

    for (int i = 1; i < n; ++i) {
        bool flg = false;

        for (int j = 0; j < b.size(); ++j) {
            if (ans[i] % b[j] != 0) {
                c.push_back(ans[i]);
                flg = true;
                break;
            }
        }

        if (!flg) {
            b.push_back(ans[i]);
        }
    }

    if (b.size() >= 1 && c.size() >= 1) {
        return b;
    } else {
        return vector<int>();
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            cin >> ans[j];
        }

        vector<int> final = solve(ans);

        if (!final.empty()) {
            vector<int> b = final;
            vector<int> c;

            for (int j = 0; j < ans.size(); ++j) {
                bool found = false;
                for (int k = 0; k < b.size(); ++k) {
                    if (b[k] == ans[j]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    c.push_back(ans[j]);
                }
            }

            cout << b.size() << " " << c.size() << endl;
            for (int j = 0; j < b.size(); ++j) {
                cout << b[j] << " ";
            }
            cout << endl;
            for (int j = 0; j < c.size(); ++j) {
                cout << c[j] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
