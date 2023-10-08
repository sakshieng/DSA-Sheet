#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

double calculate_distance(vector<int>& X, double P) {
    double max_dist = 0.0;
    for (int xi : X) {
        max_dist = max(max_dist, abs(xi - P));
    }
    return max_dist;
}

double minimize_walk_distance(int N, vector<int>& X) {
    sort(X.begin(), X.end());

    double left = X[0], right = X[N - 1];
    while (right - left >= 1e-6) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        double dist1 = calculate_distance(X, mid1);
        double dist2 = calculate_distance(X, mid2);

        if (dist1 < dist2) {
            right = mid2;
        } else {
            left = mid1;
        }
    }

    return calculate_distance(X, (left + right) / 2);
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<int> X(N);

        for (int j = 0; j < N; ++j) {
            cin >> X[j];
        }

        double result = minimize_walk_distance(N, X);
        cout.precision(6);
        cout << "Case #" << i << ": " << fixed << result << endl;
    }

    return 0;
}
