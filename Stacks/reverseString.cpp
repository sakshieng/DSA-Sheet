#include <bits/stdc++.h>
using namespace std;
string reverseString(string &str){
	stack<string> st;
    string temp = "";
    for(char c: str)
    {
        if (c==' ')
        {
            if (temp!="")
            {
                st.push(temp);
        	    temp = "";
            }
        }
        else
        {
            temp+=c;
        }
    }
    if (temp!="") st.push(temp);
    string ans;
    while(!st.empty())
    {
        ans += st.top(); st.pop();
        if(!st.empty())
    	ans+=" ";
    }   
    return ans;	
}
int main()
{
    string str;
    getline(cin, str);//as space asleli string smeans sentence input
    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;
    return 0;
}