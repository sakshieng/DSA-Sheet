#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://maang.in/mocks/attempts/2188?problem_id=236

long long solve(vector<int>& arr) {    
    sort(arr.begin(), arr.end());
    long long mini = 0;
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            mini += abs(arr[i] - arr[i + 1]);
        } else if (i == n - 1) {
            mini += abs(arr[i] - arr[i - 1]);
        } else {
            mini += min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
        }
    }

    return mini;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    long long result = solve(arr);
    cout << result << endl;

    return 0;
}
