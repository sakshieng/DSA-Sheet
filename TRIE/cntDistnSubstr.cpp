#include<bits/stdc++.h>
//https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
using namespace std;
// https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?leftPanelTab=1
#include<bits/stdc++.h>
struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch,Node *node){
        links[ch - 'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    //TC O(n^2) tries make sure it will reuse the space 
    // we can use set ds as well
    int cnt = 0;
    Node *root = new Node();
    for(int i=0;i<s.size();++i){
        Node *node = root;
        for(int j=i;j<s.size();++j){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new Node());
            }
            //go to next refrence trie
            node = node->get(s[j]);
        }
    }
    return cnt+1;//+1 for empty str
}
int matrixSum(vector<vector<int>>& nums) {
    int n = nums.size(),m = nums[0].size();
    
}