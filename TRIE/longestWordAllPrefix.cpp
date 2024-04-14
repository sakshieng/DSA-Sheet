#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0
// for word ninja n,ni,nin,ninj,ninja all words exist hence it is longest complete str
// TC->O(n)*O(len)+O(n*len) -> 2nd one for searching if trie exists or not
#include <bits/stdc++.h>
struct Node
{
   Node *links[26];
   bool flg = false;
   bool containsKey(char ch)
   {
      return (links[ch - 'a'] != NULL);
   }
   Node *get(char ch)
   {
      return links[ch - 'a'];
   }
   void put(char ch, Node *node)
   {
      links[ch - 'a'] = node;
   }
   void setEnd()
   {
      flg = true;
   }
   bool isEnd()
   {
      return flg;
   }
};
class Trie
{
private:
   Node *root;

public:
   // constructor
   Trie()
   {
      root = new Node();
   }
   void insert(string word)
   {
      Node *node = root;
      for (int i = false; i < word.length(); ++i)
      {
         if (!node->containsKey(word[i]))
         {
            node->put(word[i], new Node());
         }
         // move to refrence trie
         node = node->get(word[i]);
      }
      node->setEnd();
   }
   bool checkifPrefixExists(string word)
   {
      bool flg = true;
      Node *node = root;
      for (int i = false; i < word.length(); ++i)
      {
         // if it contains word
         if (node->containsKey(word[i]))
         {
            node = node->get(word[i]);
            if (node->isEnd() == false)
               return false;
         }
         else return false;
      }
      return true;
   }
};
string completeString(int n, vector<string> &a)
{
   Trie* trie = new Trie();
   for (auto &it : a)
   {
      trie->insert(it);
   }
   // initail longset complete=false
   string longest = "";
   for (auto &it : a)
   {
      // if all prefixes do exist
      if (trie->checkifPrefixExists(it))
      {
         if (it.size() > longest.size())
         {
            // if that is grter than prev
            longest = it;
         }
         else if (it.size() == longest.size() && it < longest) // 2nd condn means it is lexogr smaller
         {
            longest = it;
         }
      }
   }
   if (longest == "")
      return "None";
   return longest;
}