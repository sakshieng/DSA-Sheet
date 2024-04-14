// KNAPSACK PROBLEM-GREEDY ALGORITHM it is applicable to objects which are divisble
// zero-one knapsack has not allow divisible objects
#include <bits/stdc++.h>
/* Sakshi */
// v[0] no of trucks and v[1] no of units per box
using namespace std;

int main()
{
    class Solution
    {
    public:
        static bool cmp(vector<int> &v1, vector<int> &v2)
        {
            return (v1[1] > v2[1]);
            // wrt second element sort
            // only no of units per box decending order mdhe sort
            // no of units per box should be max
        }
        int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
        {
            int n = boxTypes.size();
            sort(boxTypes.begin(), boxTypes.end(), cmp);
            // cmp func is declared above by static bool
            int maxUnits = 0;
            for (int i = 0; i < n; i++)
            {
                // if we have 3 box and truck can accept only 2 then what we need to give 
                //2 na 3 so min(box & truck)
                if (truckSize < boxTypes[i][0])
                {
                    boxTypes[i][0] = truckSize;
                }
                maxUnits += boxTypes[i][1] * boxTypes[i][0];
                // boxTypes[i][0] is no of boxes
                // boxTypes[i][1] is no of units per box
                truckSize -= boxTypes[i][0];
                // as we add no of boxes trucksize will get reduced
                // boxes - 10 1)5 2)2 3)0
                // units -   1)50 2)77 3)91
            }
            return (maxUnits);
        }
    };
    return 0;
}