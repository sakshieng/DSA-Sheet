#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1862/problem/A
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> v(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int cnt=0;
        vector<char>ans;
        for(int i=0;i<m;i++)//coulm traverse
        {
            for(int j=0;j<n;j++)//row traverse
            {
                if(ans.size()==0){
                    if(v[j][i]=='v'){
                        ans.push_back(v[j][i]);
                        break;
                    }    
                }
                if(ans.size()==1){
                    if(v[j][i]=='i'){
                        ans.push_back(v[j][i]);
                        break;
                    }    
                }
                if(ans.size()==2){
                    if(v[j][i]=='k'){
                        ans.push_back(v[j][i]);
                        break;
                    }    
                }
                if(ans.size()==3){
                    if(v[j][i]=='a'){
                        ans.push_back(v[j][i]);
                        break;
                    }    
                }
            }
        }
        if(ans.size()==4){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}