// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>hash(26,0);
    vector<int>phash(26,0);
    vector<int>ans;
    int window = p.size();
    int len = s.size();
    if(len < window) return ans;
    int left = 0,right = 0;
    while(right < window){
        //for 1st window
        phash[p[right]-'a']++;
        hash[s[right++]-'a']++;
    }
    right--;
    while(right < len){
        //slide the window upto len end
        if(phash == hash) 
            ans.push_back(left);
        right++; 
        if(right != len)  {
            hash[s[right]-'a']++;//add elmt pudhcha
        }
        hash[s[left]-'a']--;//remove elmt magcha
        left++;
    }
    return ans;
    }
};

/*
s = abcdebacb
p = cab
we have to maintain freq of each char so two hash func
phash for p=cab
0 1 2 3 4 
a b c d e 
1 1 1 0 0
hash->sliding window freq i.e. s=abc of size 3
hash
0 1 2 3 4
a b c d e
1 1 1 0 0
next window bcd
so
hash +1 for d and -1 for a
0 1 1 1 0 0
if hash == phash then push starting idx of window in ans
TC->O(alphabet size*len(s))
*/