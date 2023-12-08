#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkGreater(char a , char b){
    
}
int main() {
    int n;
    cin >> n;
    unordered_map<char,int>mp;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']=5;
    mp['6']=6;
    mp['7']=7;
    mp['8']=8;
    mp['9']=9;
    mp['T']=10;
    mp['J']=11;
    mp['Q']=12;
    mp['K']=13;
    mp['A']=14;
    for (int j = 0; j < n; j++) {
        string s1, s2;
        getline(cin>>ws,s1);
        getline(cin>>ws,s2);
        
        bool a= false;
        queue<char>q1;
        queue<char>q2;
        for(int i=0;i<=s1.size();i=i+2){
            // cout<<s1[i]<<" ";
            q1.push(s1[i]);
        }
        cout<<endl;
        for(int i=0;i<=s2.size();i=i+2){
            // cout<<s2[i]<<" ";
            q2.push(s2[i]);
        }
        long long mrk=0;
        while(!q1.empty() && !q2.empty()){
            mrk++;
            if(mrk>=100000){
                a=true;
                break;
            }
            if(q1==q2)  {
                a=true;
                break;}
            
            char a=q1.front();
            q1.pop();
            char b=q2.front();
            q2.pop();
            if(mp[a]==mp[b]){
                q1.push(a);
                q2.push(b);
            }
            else if(mp[a]>mp[b]){
                q1.push(b);
            }
            else{
                q2.push(a);
            }
            
        }
        
        if(a){
            cout<<"draw\n";
        }
        else if(q1.empty()){
            cout<<"player 2\n";
        }
        else{
            cout<<"player 1\n";
        }
    }

    return 0;
}
