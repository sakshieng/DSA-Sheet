#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/maximum-number_1094876?leftPanelTab=0
vector<int> maxSwap(vector<int> &num)
{
    //greedy approach
    int N=num.size();
    int digits[10]={0}; // store last occurence of all digits
    for(int i=0;i<N;i++)
    {
        digits[num[i]]=i;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=9;j>num[i];j--)
        {
            if(digits[j]>i)//We find a maximum digit which is right side of index
            {
                swap(num[i],num[digits[j]]); //We will swap both these digits
                return num;
            }
        }
    }
    return num;
}