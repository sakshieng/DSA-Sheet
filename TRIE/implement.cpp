#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/implement-trie_631356?leftPanelTab=0
// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// Trie *obj = new Trie();
// obj->insert(word);
// bool check2 = obj->search(word);
// bool check3 = obj->startsWith(prefix);

struct Node
{
    Node *links[26];
    bool flg = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL); // means this char is exists
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node; // apples a will be pointing to new trie nodela point krtoy search char aapn means trie la
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];//gives trie of ch-'a'
    }
    bool setEnd()
    {
        return flg = true;
    }
    // for setting flg true for searching
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
    Trie()
    {
        // when object is created u will create a new node
        root = new Node();
    }

    /*tc->O(len(word)) */
    void insert(string word)
    {
        // start with root
        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            // if it doesnt contain char
            if (!node->containsKey(word[i]))
            {
                // put it
                node->put(word[i], new Node()); // put that word to new reference trie
            }
            // move to reference trie
            node = node->get(word[i]);
        }
        // when we are standing at last reference trie
        node->setEnd(); // means flg is set true and word exsits
    }

    /*tc->O(len) Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (!node->containsKey(word[i]))
                return 0;
            // if contains get me that and move to next
            node = node->get(word[i]);
        }
        // at this refernce if flg=true word exists
        if (node->isEnd() == true)
            return 1;
        return 0;
        // return node->isEnd();
    }
    /*tc->O(len) Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if (!node->containsKey(prefix[i]))
                return 0;
            node = node->get(prefix[i]);
        }
        return 1;
    }
};