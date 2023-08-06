#include <iostream>
#include <vector>
using namespace std;

long long Sum(vector<int>& arr) {
    int N = arr.size();
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] % 4 == arr[j] % 4) {
                sum += arr[i] ^ arr[j];
            }
        }
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long sum = Sum(arr);
        cout << sum << endl;
    }

    return 0;
}