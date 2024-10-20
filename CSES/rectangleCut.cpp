// https://cses.fi/problemset/task/1744
#include <iostream>
using namespace std;

int minCuts(int a, int b) {
    if (a < b) swap(a, b); // Ensure a >= b
    int cuts = 0;
    while (b > 0) {
        cuts += a / b; 
        int temp = b;
        b = a % b; 
        a = temp;
    }
    return cuts;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << minCuts(a, b) << endl;
    return 0;
}
 
