// https://www.geeksforgeeks.org/problems/smith-number4132/1
#include <bits/stdc++.h>
using namespace std;

//sum of digits = sum of prime factors
class Solution {
  public:
    int sumofDigits(int n){
        int sum = 0;
        while (n)
        {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    bool isPrime(int n){
        if(n <= 1){
            return 0;
        }
        for (int i = 2; i <= sqrt(n); i++)
        {
            if(n%i == 0)
                return 0;
        }
        return 1;
    }
    int sodPrimeFactors(int n){
        int sum = 0;
        for(int i=2;i<=sqrt(n);++i) {
            while (n%i == 0)
            {
                sum += sumofDigits(i);
                n /= i;
            }
        }
        if(n > 1)   sum += sumofDigits(n);
        return sum;
    }
    int smithNum(int n) {
        if(isPrime(n))
            return 0;
        return (sumofDigits(n) == sodPrimeFactors((n)));
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}