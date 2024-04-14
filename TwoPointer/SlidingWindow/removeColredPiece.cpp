#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/?envType=daily-question&envId=2023-10-02
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<=2) return 0;
        int i=0,j=2;
        int cA=0,cB=0;
        while(j<n)
        {
            if(colors[i]=='A' and colors[i+1]=='A' and colors[j]=='A')
            {
                cA++;
                // i++;j++;
            }
            else if(colors[i]=='B' and colors[i+1]=='B' and colors[j]=='B')
            {
                cB++;
                // i++;j++;
            }
            i++;
            j++;

        }
        cout<<cA<<" "<<cB<<"\n";
        if(cA==cB) return 0;
        if(cA>cB) return 1;
        else return 0;
    }
};