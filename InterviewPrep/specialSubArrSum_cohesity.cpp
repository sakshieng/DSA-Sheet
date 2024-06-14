#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://maang.in/mocks/attempts/2207?problem_id=72
//the better aproach of this problem is to find the max and min of all subarrays by next greater next smaller 
vector<vector<int>>generateAllSubarr(vector<int>&arr)
{
    vector<vector<int>>res;
    int n=arr.size();
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            vector<int>temp;
            for (int i = start; i <= end; i++)
            {
                temp.push_back(arr[i]);
            }
            res.push_back(temp);
        }
        
    }
    return res;
}
//find difference of max and min of all subarrays
int specialSubArrSum(vector<int>&arr)
{
    vector<vector<int>>allSubarr=generateAllSubarr(arr);
    int sum=0;
    for (int i = 0; i < allSubarr.size(); i++)
    {
        int max=*max_element(allSubarr[i].begin(),allSubarr[i].end());
        int min=*min_element(allSubarr[i].begin(),allSubarr[i].end());
        sum+=max-min;
    }
    return sum;
} 
int main()
{
   int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<specialSubArrSum(arr)<<endl;
    }
   return 0;
}