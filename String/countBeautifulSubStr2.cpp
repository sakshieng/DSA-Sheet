#include <bits/stdc++.h>
//https://leetcode.com/contest/weekly-contest-373/problems/count-beautiful-substrings-ii/
using namespace std;
class Solution
{
private:
    bool isVowel(char c) {
        c = toupper(c);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
public:
    int beautifulSubstrings(string s, int k)
    {
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int vowel_cnt = 0,conso_cnt = 0;
            for (int j = i; j < n; j++)
            {
                if(isVowel(s[j]))
                    vowel_cnt++;
                else
                    conso_cnt++;
                if(vowel_cnt==conso_cnt && ((vowel_cnt*conso_cnt)%k == 0))
                    cnt++;
            }
        }
        return cnt;        
    }
};