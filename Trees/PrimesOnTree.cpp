// https://codedrills.io/problems/primes-on-a-tree
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
const int mod = 1000000007;
class PrimeTree {
public:
bool isPrime(int n){
      static int i = 2;
 
    if (n == 0 || n == 1) 
        return 0;
    if (n == i)
        return 1;
 
    if (n % i == 0) 
        return 0;
    i++;
    return isPrime(n);
}
vector<int>primes;
vector<vector<int>>adj;
vector<vector<long long>>dp;
void preProcess(int n){
    for(int i=2;i<=100;++i)
        if(isPrime(i))
            primes.push_back(i);
    adj.clear();
    adj.resize(n);
    dp.clear();
    dp.assign(n,vector<long long>(primes.size(),1));
}
void dfs(int node,int par){
    for(int )
}
	int getNumberOfArrangements(int N, std::vector<std::vector<int>> edges) {
        if(n == 1)
            return 25;
        else    
            return n-k;
	}
};
