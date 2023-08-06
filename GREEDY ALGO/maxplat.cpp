#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
    //    TC-->O(2n*log n)   +   O(2n)
    //          as 2 loops      2-pointer approach
    // SC-->O(1)
    // if arrival train and departure train will be at same time we will require one more platform
    class Solution
    {
    public:
        // Function to find the minimum number of platforms required at the
        // railway station such that no train waits.
        int findPlatform(int arr[], int dep[], int n)
        {
            sort(arr, arr + n);
            sort(dep, dep + n);
            int plat_needed = 1, result = 1;
            int i = 1, j = 0;
            while (i < n && j < n)
            {
                if (arr[i] <= dep[j])
                {
                    plat_needed++;
                    i++;
                }
                else if (arr[i] > dep[j])
                {
                    plat_needed--;
                    j++;
                }
                if(plat_needed > result) result=plat_needed;
            }
        }
    };
    return 0;
}