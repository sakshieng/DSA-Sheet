#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/subset-sum_3843086?leftPanelTab=0
using namespace std;

vector<int>tmp;
void help(vector<int>& nums,int i,int sum ){
    if(i >= nums.size())
    {   
        tmp.push_back(sum);
        return;
    }
    help(nums,i+1,sum);
	sum += nums[i];
    help(nums,i+1,sum);
	sum -= nums[i];
}
vector<int> subsetSum(vector<int> &num){
    int sum=0;
	help(num,0,sum);
    sort(tmp.begin(),tmp.end());
	return tmp;
}