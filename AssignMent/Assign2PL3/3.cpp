// Given an array A of n elements, each of which is an integer in the range [1, n2]. How do we sort the array in O(n) time?
#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& A, int n) {
    int maxElement = n * n;
    vector<int> count(maxElement + 1, 0);

    for (int i = 0; i < n; ++i) {
        count[A[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 1; i <= maxElement; ++i) {
        while (count[i] > 0) {
            A[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> A = {4, 2, 3, 1, 8, 6, 5, 7};
    int n = A.size();

    countingSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
