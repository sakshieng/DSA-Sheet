#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// GREEDY ALGORITHM 
int main()
{
    class Solution
   
    {
    public:
        int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
        {
            horizontalCuts.push_back(h);
            //by push back h we can compare if 7 dia hai aur 1 3 5 ke bich mai se max nikalna hai na toh it will comapre 7-5 as well havent added this h further becauz it will add directly to array so will check h che pn
            verticalCuts.push_back(w);
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());
            long long int i = 0, j = 0,val;
            long long int leng = horizontalCuts[0], wid = verticalCuts[0];
            int m = horizontalCuts.size();
            int n = verticalCuts.size();
            for (i = 0; i < m - 1; i++)
            {
                val = horizontalCuts[i + 1] - horizontalCuts[i];
                leng = max(leng, val);
                // max value in between leng and val is stored to leng
            }
            for (j = 0; j < n - 1; j++)
            {
                val = verticalCuts[j + 1] - verticalCuts[j];
                wid = max(wid, val);
            }
            int ans=((leng%1000000007)*(wid%1000000007))%1000000007;
            return ans;
        }
    };

   return 0;
}
// Algorithm :

// 1.Sort both the array to get the cuts in sequential way
// 2.Find the max Height
// 3.Find the max Width
// 4.Return the area as (max Height * max Width)