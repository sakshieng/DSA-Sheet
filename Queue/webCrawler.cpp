/*
web crawler is bot that automatically crawls through pages and extracts info 
*/
// #include<bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution {
public:
    vector<string>crawl(string startUrl,Htmlparser htmlParser){
        queue<string>q;
        unordered_set<string>vis;
        string hostname = startUrl.substr(0,startUrl.find('/',7));
        string path = startUrl.substr(startUrl.find('/',7));
        q.push(startUrl);
        vis.insert(startUrl);

        while(!q.empty()){
            string curr = q.front();
            q.pop();
            vector<string>childUrls = htmlParser.getUrls(hostname + curr);
            for(string &childUrl:childUrls){
                if(vis.find(childUrl) == vis.end()){
                    q.push(childUrl);
                    vis.insert(childUrl);
                }
            }
        }
        return vector<string>(vis.begin(),vis.end());
    }
   
};
