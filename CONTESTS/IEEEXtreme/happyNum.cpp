#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll nextNumber(ll n){
        ll newNumber = 0;
        while(n!=0){
            ll num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
    bool isHappy(ll n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1;
    }
int main() {
    long long a, b;
    cin >> a >> b;
    long long ans=0;
    for(int i=a;i<=b;i++){
        if(isHappy(i))  ans++;
    }

    return 0;
}
