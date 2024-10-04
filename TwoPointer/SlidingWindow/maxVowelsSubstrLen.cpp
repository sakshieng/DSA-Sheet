// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        //we need to initialze the first window of size k
        int currCntVowel = 0, maxCntVowel = 0;
        for (int i = 0; i < k; i++)
        {
            if(isVowel(s[i])) currCntVowel++;
            maxCntVowel = max(maxCntVowel, currCntVowel);
        }
        for (int i = k; i < s.size(); i++)
        {
            if(isVowel(s[i])) currCntVowel++;
            if(isVowel(s[i - k])) currCntVowel--;
            maxCntVowel = max(maxCntVowel, currCntVowel);
        }
        
        return maxCntVowel;
    }
};
/*
For s = "abciiidef" and k = 3:
make the window of k size
abc -> 1
bci -> 2
cii -> 2
iii -> 3
continue end

*/
void fun(int *p) 
{ 
  int q = 10; 
  p = &q; 
}     
  
int main() 
{ 
  int r = 20; 
  int *p = &r; 
  fun(p); 
  cout<<*p;
  return 0; 
}