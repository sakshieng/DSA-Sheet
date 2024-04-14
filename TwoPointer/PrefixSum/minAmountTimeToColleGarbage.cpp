//try to find the last position of M-truck/G-truck/P-truck
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        int n = garbage.size();
        int G_idx = 0,M_idx = 0,P_idx =0;
        //tc O(n*10) as garbage arr size = 10
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < garbage[i].length(); j++)
            {
                if(garbage[i][j] == 'M')
                    M_idx = i;
                else if(garbage[i][j] == 'P')
                        P_idx = i;
                    else
                        G_idx = i;
                time++;//for all pickups we have to +1 time
            }
            
        }
        //prefix sum
        for (int i = 1; i < travel.size(); i++)
            travel[i] += travel[i-1];
        
        time += M_idx>0 ? travel[M_idx-1]:0;//time taken to travel house for M truck
        time += P_idx>0 ? travel[P_idx-1]:0;//time taken to travel house for P truck
        time += G_idx>0? travel[G_idx-1]:0;//time taken to travel house for G truck
        return time;
    }
};