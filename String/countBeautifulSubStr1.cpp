#include <bits/stdc++.h>
// https://leetcode.com/contest/weekly-contest-373/problems/count-beautiful-substrings-i/
using namespace std;
class Solution
{
private:
    bool isVowel(char c) {
        c = toupper(c);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
public:
    long long beautifulSubstrings(string s, int k)
    {
        long long cnt = 0;
        long long n = s.length();
        vector<long long> prefixVowels(n + 1, 0);
        vector<long long> prefixConsonants(n + 1, 0);

        for (long long i = 1; i <= n; ++i) {
            prefixVowels[i] = prefixVowels[i - 1] + isVowel(s[i - 1]);
            prefixConsonants[i] = prefixConsonants[i - 1] + !isVowel(s[i - 1]);
        }

        for (long long i = 0; i < n; ++i) {
            for (long long j = i + 1; j <= n; ++j) {
                long long vowels_count = prefixVowels[j] - prefixVowels[i];
                long long conso_count = prefixConsonants[j] - prefixConsonants[i];

                if (vowels_count == conso_count && (vowels_count * conso_count) % k == 0)
                    cnt++;
            }
        }

        return cnt;       
    }
};