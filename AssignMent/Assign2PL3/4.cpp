//Let A and B tow arrays of n elements, each. Given a number K, give an O (nlogn) time algorithm for determining whether there exists a ϵ A and b ϵ B such that a+b =K.
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


bool hasPairWithSum(vector<int>& A, vector<int>& B, int K) {
    sort(B.begin(), B.end());//ascending order

    for (int a : A) {
        int target = K - a;
        auto it = lower_bound(B.begin(), B.end(), target);

        if (it != B.end() && *it == target) {
            return true;
        }
    }

    return false;//no pair found
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {6, 7, 8, 9, 10};
    int K = 12;

    if (hasPairWithSum(A, B, K)) {
        cout << "There exists a pair (a, b) such that a + b = " << K << endl;
    } else {
        cout << "No such pair found." << endl;
    }

    return 0;
}
