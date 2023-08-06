#include <iostream>
#include <vector>
using namespace std;
// https://www.hackerrank.com/contests/pre-compute-it/challenges

/*
Sample Input 
2
4
10 50 100  130
5
10 60 80 110 150 

Sample Output 
3
2
*/
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int P[N];
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        int maxi = 0;
    int max_day = 0;

    for (int i = 0; i < N; i++) {
        int current_people = P[i] - (i > 0 ? P[i - 1] : 0);

        if (current_people > maxi) {
            maxi= current_people;
            max_day = i + 1;
        }
    }
        
        cout << max_day << endl;
    }

    return 0;
}
