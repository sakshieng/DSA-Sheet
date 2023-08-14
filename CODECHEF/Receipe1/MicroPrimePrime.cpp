#include <iostream>
using namespace std;
// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/
const int N = 1e6;
int arr[N + 1];
int primePrime[N + 1];
int primePrimePrefix[N+1];
//precompute the primprime
void sieve() {
    for (int i = 0; i <= N; ++i) {
        arr[i] = 1;
        primePrime[i] = 0; // Not a prime prime number
    }
    arr[0] = arr[1] = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= N; j += i) {
                arr[j] = 0; // It is not a prime number
            }
        }
    }
    int cnt = 0,cnt_pp=0;
    for (int i = 2; i <= N; ++i) {
         
        if (arr[i] == 1) {
			cnt++;
            // We got a prime number
		}
        if (arr[cnt] == 1) {
            primePrime[i] = 1;
			cnt_pp++;
        }
		primePrimePrefix[i] = cnt_pp;
    }
}


int main() {
    int num;
    cin >> num;
    sieve();
    while (num--) {
        int l, r;
        cin >> l >> r;
        
        cout<<primePrimePrefix[r]-primePrimePrefix[l-1];
        cout << "\n";
    }
    return 0;
}
