#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    int n = expression.length();
    stack<char>st;
    for(int i=0;i<n;++i){
        if(st.empty()) st.push(expression[i]);
        else if(st.top()=='{' and expression[i]=='}') st.pop();
        else if (st.top() == '[' && expression[i] == ']') st.pop();
        else if (st.top() == '(' && expression[i] == ')') st.pop();
        else if (st.top() == '[' && expression[i] == ']') st.pop();
        else st.push(expression[i]);
    }
    return st.empty();
}
int main()
{
   int t;
   cin>>t;
   while (t--)
   {
    string s;
    cin>>s;
    bool ans = false;
    ans = isValidParenthesis(s);
    cout<<ans<<"\n";
   }
   return 0;
}