#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

class Solution
{
public:
   static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second<p2.second;            
    }
    int maxMeetings(int start[],int end[],int n)
    {
        vector<pair<int,int>>ans;
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(start[i],end[i]);
            /*
            1 2
            3 4
            0 6
            5 7
            5 9
            8 9
            */
        }
        // jyacha object create krycha nhiye mg static func kra in class or else baher kra class chya without static
        // p1 1st return krtey jevha true ahe  
        int cnt=0;
        sort(ans.begin(),ans.end(),cmp);
        pair<int,int>curr={0,0};
        for(int i=0;i<n;++i)   
        {
            if(v[i].first>curr.second)
            {
                cnt++;
                curr=v[i];
            }
        }
        return cnt;
    }
};

/*
factorial knapsack 
           thief
for c++-->priority queue
default descending-->max heap
           
for java-->priority queue
default ascending-->min heap

sorting -->n logn
we are sorting and then storing
insertion TC-->nlogn
*/
