#include <iostream>
#include <vector>

using namespace std;

long canSeePersonsCount(vector<long>& heights) {
    vector<long> stack;
    int n = heights.size();
    vector<long> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = stack.size();

        while (!stack.empty() && stack.back() <= heights[i]) {
            stack.pop_back();
        }

        stack.push_back(heights[i]);
    }

    long sum = 0;
    for (long e : ans) {
        sum += e;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    long h0, a, c, q;
    cin >> h0 >> a >> c >> q;
    vector<long> arr(n);

    arr[0] = h0;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + c) % q;
    }

    int i = 0, j = n - 1;
    while (i < j) {
        long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i += 1;
        j--;
    }

    cout << canSeePersonsCount(arr) << endl;

    return 0;
}
