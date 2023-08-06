// https://www.codingninjas.com/studio/problems/minimum-number-of-swaps-required-to-sort-an-array_973251
#include <bits/stdc++.h> 
using namespace std;
void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int indexOf(vector<int>& arr, int ele)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == ele) {
            return i;
        }
    }
    return -1;
}

int minSwaps(vector<int> &arr)
{
	int ans = 0;
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
 
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] != temp[i]) {
            ans++;

            swap(arr, i, indexOf(arr, temp[i]));
        }
    }
    return ans;
}