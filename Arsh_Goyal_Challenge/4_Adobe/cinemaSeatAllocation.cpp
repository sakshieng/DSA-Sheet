#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://leetcode.com/problems/cinema-seat-allocation/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://leetcode.com/problems/cinema-seat-allocation/description/
class Solution {
public:
//n = 10^9 so O(n)pn TC nhi allowed reserved seats O(n) chalel as n  = 1e4 easy simulation->do whatever is said by using flgs
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //if all rooms are empty in one vector then 2 seats allocated
        sort(reservedSeats.begin(),reservedSeats.end());
        map<int,vector<int>>mp;
        int ans = 0;
        for(auto &i:reservedSeats){
            //i[0]->which row i[1]->which seat is occupied
            mp[i[0]].push_back(i[1]);
        }

        for(auto &i:mp){
            vector<int>row = i.second;
        bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
            //because the seats 1and 10 are useless 
            for (int i = 0; i < row.size(); i++)
            {
                if(row[i] == 2 or row[i] == 3)
                    flag1 = 0;
                if(row[i] == 4 or row[i] == 5)
                    flag2 = 0;
                if(row[i] == 6 or row[i] == 7)
                    flag3 = 0;
                if(row[i] == 8 or row[i] == 9)
                    flag4 = 0;
            }
            if(flag1 && flag2) ans++;
            if(flag3 && flag4) ans++;
            if(flag3 && flag4) ans++;
            if(flag2 && flag3) ans++;
        }
        ans += ((n - mp.size())*2);
        // mp == busy rows so total free rows = n-mp.size()
        return ans;
    }
};