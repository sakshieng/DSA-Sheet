//bob asks a bot Q queries bot searches db for any prev stored game
//find min no of games stored in db that have provided in prefix
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

vector<int>BobBot(nt N, int M, vector<vector<int>> games, int Q, vector<vector<int>> queries){
    vector<int>res;
    for (int i = 0; i < N; i++)
    {
        while (games.size() && games[i].back() == -1)
        {
            games[i].pop_back();
        }
    }
    for (auto &&query : queries)
    {
        while (query.size() && query.back() == -1) query.pop_back();
        int cnt = 0;
        for(int i=0;i < N;++i){
            bool flg = true;
            for (int j = 0; j < query[i].size(); j++)
            {
                if(games[i][j] != query[j])
                    flg = false;
            }
            cnt += flg;
        }
        res.push_back(cnt);
    }
    return res;
}
