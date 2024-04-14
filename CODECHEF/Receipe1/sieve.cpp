// finding the the highest prime factor / lowest prime factor
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
const int N = 1e6;
int arr[N + 1];
void seive()
{
    for (int i = 0; i < N; ++i)
        arr[i] = 1;
    arr[0] = arr[1] = 1;
    for (int i = 2; i * i <= N; ++i)
    {
        if (arr[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
            {
                arr[i] = 0;
            }
        }
    }
}
//log base highest prime factor*n TC for printing all prime factors i.e.TC->O(logn) if no is prime TC->O(n)
//prime factors by always so optimize TC -> O(log n) by doing spf
void primeFactors(int n){
    for(int i=2;i*i<=n;++i){
        //as prime factors will get before root(n)so for loop will be i*i<=n will work as well
        int cnt=0;
        while(n%i == 0){
            cnt++;
            n = n/i;
        }
        if(cnt != 0) cout<<i<<"^"<<cnt;
    }
    cout<<"\n";
}