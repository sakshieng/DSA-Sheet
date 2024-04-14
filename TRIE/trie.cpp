#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*


-> Only the leaf nodes of a trie represent strings from the set.
->The internal nodes represent prefixes of strings in the set
->The SC(trie) and SC(balanced BST) are both O(n), where n is no of strings in the set 
the SC of a trie can be better than a BST if the strings in the set have a lot of common prefixes.
->The leaf nodes of a trie can have different depths, depending on the length of the strings they represent.



=> how the time complexity of searching a string in a trie works.


The first character of the string is matched to one of the child nodes of the root node.
The second character of the string is matched to one of the child nodes of the current node.
This process continues until all the characters of the string have been matched.
The total number of comparisons performed is equal to the length of the string. Therefore, the time complexity for searching a string of length k is O(k).
*/
struct TrieNode
{
  TrieNode *children[2];
  TrieNode()
  {
    children[0] = nullptr;
    children[1] = nullptr;
  }
};

// Function to insert a number into the trie
void insertNumber(TrieNode *root, int num)
{
  TrieNode *curr = root;
  for (int i = 31; i >= 0; i--)
  {
    int bit = (num >> i) & 1;
    if (curr->children[bit] == nullptr)
    {
      curr->children[bit] = new TrieNode();
    }
    curr = curr->children[bit];
  }
}

// Function to find the maximum XOR value
int findMaxXOR(vector<int> &nums)
{
  int max_xor = 0;
  int cur_xor = 0;
  TrieNode *root = new TrieNode();

  // Insert prefix 0 into trie
  insertNumber(root, 0);

  for (int num : nums)
  {
    cur_xor ^= num;
    insertNumber(root, cur_xor);

    TrieNode *curr = root;
    int xor_val = 0;
    for (int i = 31; i >= 0; i--)
    {
      int bit = (cur_xor >> i) & 1;
      if (curr->children[1 - bit] != nullptr)
      {
        xor_val |= (1 << i);
        curr = curr->children[1 - bit];
      }
      else
      {
        curr = curr->children[bit];
      }
    }
    max_xor = max(max_xor, xor_val);
  }

  return max_xor;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
      cin >> ans[i];
    int mxii;
    mxii = findMaxXOR(ans);
    cout << mxii << endl;
  }
  return 0;
}
