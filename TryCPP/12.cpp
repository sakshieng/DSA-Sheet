#include<bits/stdc++.h>
//sakshi codes here
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
int main()
{
   int t;cin>>t;
   while (t--)
   {
    int n;cin>>n;
    vector<int>tmp(n);
    for (int i = 0; i < n; i++)
    {
        cin>>tmp[i];
    }
    int cnt = 0;
    vector<int>arr(tmp.begin(),tmp.end());
     for (int i = 0; i < n; i++){
        if(tmp[i] != arr[i]) {
            cnt++;
            swap(tmp,i,indexOf(tmp,arr[i]));
        }
     }
    cout<<cnt<<endl;
   }
   
   return 0;
}