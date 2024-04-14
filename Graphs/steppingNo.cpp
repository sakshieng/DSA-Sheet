#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1
class Solution{
public:
    int ans;
    void dfs(int curr,int n, int m){
        if(curr > m) return;
        if(curr<=m && curr>=n){
            ans++;
        }
        int lastDigit = curr%10;
        if(lastDigit == 9){
            dfs(curr*10+8,n,m);
        }else if(lastDigit == 0){
            dfs(curr*10+1,n,m);
        }else{
            dfs(curr*10+(lastDigit+1),n,m);
            dfs(curr*10+(lastDigit-1),n,m);//1 to 8 append
        }
    }
    int steppingNumbers(int n, int m)
    {
        ans = 0;
        if(n == 0) ans++;//low 0 so 1 subtract yenar
        for(int i=1;i<=9;++i){
            dfs(i,n,m);
        }
        return ans;
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        int ans = obj.steppingNumbers(n,m);
        cout << ans << endl;
    }
	return 0;
}

