/*
different domain name and local names should be correctly put into the set
parsing of string
traverse from end of str push each char to diff str1 as domain name and str2 as local name
as valid email consists of a local name and a domain name they are separated by '@' 
'.' in local name -> mail will sent to same addr without dots in local name=>'.' is ignored
'+' in local name => everything after that is ignored
*/
#include<bits/stdc++.h>
//https://leetcode.com/problems/unique-email-addresses/
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        set<string>st;
        for(int i=0;i<n;++i){
            string back = "";//to find domain
            while(emails[i].back() != '@'){
                back = (char)(emails[i].back()) + back; 
                emails[i].pop_back();
            }
            emails[i].pop_back();//for removing @ sign
            string start = "";//local name
            for(int j=0;j < (int)emails[i].size();++j){
                if(emails[i][j] == '+') 
                    break;
                else if(emails[i][j] == '.')
                    continue;
                else
                    start += (char)(emails[i][j]);
            }
            string actualEmail = start + (char)('@') + back;
            st.insert(actualEmail);
        }
        return (int)(st.size());
    }
};