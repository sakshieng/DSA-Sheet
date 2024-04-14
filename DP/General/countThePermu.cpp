#include<bits/stdc++.h>
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/little-jhool-and-too-many-products-2804a098/editorial/
using namespace std;
const int MOD = 1e9+9;
const int maxn=999;

int f[maxn+5][maxn+5];

void solution() {
	for (int n=0;n<=maxn;n++) f[n][maxn+1]=0;
	f[0][maxn+1]=1;
	for (int k=maxn;k>0;k--) 
		for (int i=0;i<=maxn;i++) {
			f[i][k]=f[i][k+1];
			if (i-k>=0) {
				f[i][k]+=f[i-k][k];
				if (f[i][k]>=MOD) f[i][k]-=MOD;
			}
		}
}

int main() {
	solution();
	int tc;
	cin>>tc;
	while (tc--) {
		int a,s;
		cin>>a>>s;
        cout<<f[a][s]<<"\n";
	}	
	return 0;
}