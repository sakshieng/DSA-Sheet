#include<bits/stdc++.h>
//sakshi codes here
//https://maang.in/mocks/attempts/2149?problem_id=159
using namespace std;

bool compareStr(string s,string t){
    auto processStr = [](string str){
        stack<char>st;
        for(auto c:str){
            if(c == '#'){
                if(!st.empty()) st.pop();
            }else{
                st.push(c);
            }
        }
        string res;
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    };
    return processStr(s) == processStr(t);
}
int main()
{
   string s,t;cin>>s>>t;
   if(compareStr(s,t)) cout<<"Yes\n";
   else cout<<"No\n";
   return 0;
}