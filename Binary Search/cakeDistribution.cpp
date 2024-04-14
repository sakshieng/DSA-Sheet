// https://www.geeksforgeeks.org/problems/cake-distribution-problem--170647/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        long long left = 1; // minimum sweetness
        long long right = 1e18; // maximum sweetness

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (isPossible(sweetness, N, K, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left - 1; // We subtract 1 to get the maximum sweetness that the Geek can get.
    }

private:
    bool isPossible(vector<int>& sweetness, int N, int K, long long target) {
        int pieces = 0;
        long long currentSweetness = 0;

        for (int i = 0; i < N; ++i) {
            currentSweetness += sweetness[i];

            if (currentSweetness >= target) {
                currentSweetness = 0;
                pieces++;

                if (pieces > K) {
                    return true;
                }
            }
        }

        return false;
    }
};

