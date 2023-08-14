#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

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
