#include<bits/stdc++.h>
//Semi Eular Graph
// https://leetcode.com/problems/reconstruct-itinerary/?envType=daily-question&envId=2023-09-14
using namespace std;

class Solution {
public:
unordered_map<string, vector<string>>flights;
vector<string>final;
void dfs(string airport){
    vector<string>&destin = flights[airport];
    //visit desti in lex order
    while(!destin.empty()){
        string next = destin.back();
        destin.pop_back();
        dfs(next);
    }
    final.push_back(airport);//adding curr airport to final after visiting all
}
vector<string> findItinerary(vector<vector<string>>& tickets) {
    for(int i=0;i<tickets.size();++i){
        string from = tickets[i][0];
        string to = tickets[i][1];
        flights[from].push_back(to);
    }
    //sort in reverse as lexical smaller desti will gets visited first
    for(auto &it:flights){
        sort(it.second.rbegin(), it.second.rend());
    }
    dfs("JFK");//straing point
    reverse(final.begin(),final.end());
    return final;
    }
};
/*
task is to create an iternary starting with JFK making sure that each ticket are used once
the graph we will build out of tickets list is Semi Euler path it is a graph in which there is a path from starting node to ending node & use all edges once
for a directed graph to be a Semi Euler graph if:
indegree of all nodes = outdegree of all nodes 
except for 2 node:
starting node have out=in+1
ending node have in=out+1
dfs recursive
tc O(n^2(log N))
sc O(N+E)
dfs iterative
tc O(n^2(log N))
sc O(N+E)
*/