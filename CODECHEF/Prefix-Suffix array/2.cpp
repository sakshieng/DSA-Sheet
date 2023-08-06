#include <iostream>
#include <vector>
using namespace std;
/*
Sample Input 
2
6
300 270 230 200 150 120
4
400  340  310  240 

Sample Output 
50
70
*/

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int S[N];
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
         int maxi = 0;

    for (int i = 0; i < N - 1; i++) {
        int curr = S[i] - S[i + 1];

        if (curr> maxi) {
            maxi= curr;
        }
    }
       
        cout << maxi<< endl;
    }

    return 0;
}