#include<bits/stdc++.h>
//https://leetcode.com/problems/search-suggestions-system/
using namespace std;

struct Node
{
    Node *links[26] = {NULL};
    bool isEnd = 0;
    int pref , end;
    vector<string>suggestions;
    void append(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool contains(char ch){
        return links[ch - 'a'] != nullptr;
    }
    void markEnd(){
        isEnd = 1;
    }
    bool checkEnd(){
        return isEnd;
    }
    int geEnds(){
        return end;
    }
    void putSuggestions(string word){
      if(suggestions.size() < 3)  
        suggestions.push_back(word);
    }
    vector<string>getSuggestions(){
        return suggestions;
    }
};

class Solution {
public:
//the que has multiple strings->trie
    void insert(Node *trie,string word){
        for (int i = 0; i < word.length(); i++)
        {
            if(!trie->contains(word[i]))
                trie->append(word[i],new Node());
            trie = trie->get(word[i]);
            trie->putSuggestions(word);
        }
        trie->markEnd();        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        int n = s.size();
        vector<vector<string>>ans(n);
        sort(begin(products),end(products));
        //imp
        Node* root = new Node();
        Node* node = root;
        Node* tmp = root;
        for(string word:products)
            insert(root,word);//root cha toh child word ahe
        root = tmp;
        int i = 0;
        for(char ch:s){
            if(node->contains(ch))
                node = node->get(ch);
            else    
                break;
            ans[i++] = node->getSuggestions();
        } 
        return ans;
    }
};