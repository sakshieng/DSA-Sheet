#include <bits/stdc++.h>
// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
using namespace std;
#define MAX_CHARS 256

// Function to check if two strings are isomorphic.
bool areIsomorphic(string str1, string str2)
{

  if (str1.size() != str2.size())
    return false;

  unordered_map<char, char> mp1;
  unordered_map<char, char> mp2;
  for (int i = 0; i < str1.size(); i++)
  {
    if ((mp1.count(str1[i]) && mp1[str1[i]] != str2[i]) || (mp2.count(str2[i]) && mp2[str2[i]] != str1[i]))
      return false;
    else
    {
      mp1[str1[i]] = str2[i];
      mp2[str2[i]] = str1[i];
    }
  }
  return true;
}
