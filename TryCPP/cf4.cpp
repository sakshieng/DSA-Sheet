#include <iostream>
#include <vector>
using namespace std;
bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}
#include <iostream>
#include <vector>
using namespace std;

int perform_operations(vector<int>& arr) {
    int count = 0;
    while (!isSorted(arr)) {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = max(0, arr[i] - arr[i - 1]);
        }
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int result = perform_operations(a);
        cout << result << endl;
    }

    return 0;
}
