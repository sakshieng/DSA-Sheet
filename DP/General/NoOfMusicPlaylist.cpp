#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-music-playlists/description/

class Solution {
public:
    #define ll long long int
    int N,Goal,K;
    const int mod = 1e9+7;
    ll dp[101][101];
    ll solve(int usedSong,int currL){
        if(currL == Goal) return usedSong == N;//all the songs which i used should be played means achieved goal

        if(dp[usedSong][currL] != -1) return dp[usedSong][currL];

        ll usedSongPlay = (solve(usedSong,currL+1) * max(0,usedSong-K))%mod;//no of used song we can take no incre used as we are using song which is already present 

        ll newSongPlay = (solve(usedSong+1,currL+1) * (N-usedSong))%mod;//new=N-used

        ll total = (usedSongPlay+newSongPlay)%mod;

        return dp[usedSong][currL] = total%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->N = n;
        this->Goal = goal;
        this->K = k;
        memset(dp,-1,sizeof(dp));
        return (int) solve(0,0);
    }
};
/*
we have 2 options either we can place used song / new song
no of old songs = used songs - k
if usedSongs<k no way to choose old songs
we need usedSongs and currLocn
multiply the songs which we are playing for used no incre but forn new play used+1 
*/