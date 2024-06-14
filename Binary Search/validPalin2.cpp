#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

//https://leetcode.com/problems/valid-palindrome-ii/description/?envType=problem-list-v2&envId=roqow5ac
class Solution {
public:
    bool isPalindrome(string::iterator low, string::iterator high) {
        while (low < high) {
            if (*low != *high)
                return false;
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string str) {
        int low = 0, high = str.length() - 1;

        while (low < high) {
            if (str[low] == str[high]) {
                low++;
                high--;
            } else {
                return isPalindrome(str.begin() + low + 1, str.begin() + high) || isPalindrome(str.begin() + low, str.begin() + high - 1);
            }
        }
        return true; //  string is already a palindrome
    }
};
