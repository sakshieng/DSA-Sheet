// pow(a,b) O(log n)-TC returns double

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

//recursive method for power func
long long binaryRecu(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long x = binaryRecu(a, b / 2);
    if (b % 2 != 0)
    {
        return a * x * x;
    }
   else return x*x;
}
//iterative method
long long binaryIter(long long a,long long b){
    long long ans = 1;
    while(b > 0){
        //if odd
        if(b & 1){//set bit is there or not
            ans = ans * a;
        }
        a = a*a;
        b /= 2;//b/=2
    }
    return ans;
}
//gcd
long long gcd(long long a,long long b){
    if(b == 0) return a;
    return gcd(b%a,a);
}
int main(){
    cout<<binaryRecu(2,20)<<"\n";
    cout<<binaryIter(2,20)<<"\n";
    // cout<<pow(2,15);
    cout<<gcd(2,0)<<"\n";
    
}