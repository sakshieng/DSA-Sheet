// https://leetcode.com/problems/throne-inheritance/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class ThroneInheritance {
public:
//dfs+tree+hashmap
    unordered_map<string,vector<string>>adjList;
    string source;
    unordered_set<string>dead;
    ThroneInheritance(string kingName) {
        source = kingName;//means it is root of tree
    }
    
    void birth(string parentName, string childName) {
        adjList[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    //by recursion using dfs
    void dfs(string curr,unordered_set<string>&visited,vector<string>ans){
        if(visited.find(curr) != visited.end())
            return;//as visited array is set which has all unique elmts now elmt is found in the set
        visited.insert(curr);
        if(dead.find(curr) == dead.end())
            ans.push_back(curr);//means he is not dead
        for(string next:adjList[curr])
            dfs(next,visited,ans);// Recursively visit the person's children
    }
    vector<string> getInheritanceOrder() {
        unordered_set<string>visited;
        vector<string>ans;
        dfs(source,visited,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */