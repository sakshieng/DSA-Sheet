#include <bits/stdc++.h> 
using namespace std;
// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?leftPanelTab=0
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])i++;
        else if(arr2[j]<arr1[i])j++;
    }
    return ans;
 
}