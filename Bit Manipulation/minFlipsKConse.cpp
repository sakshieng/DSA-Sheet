// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
    // works for 3 <= nums.length <= 105 0 <= nums[i] <= 1
public:
    int minOperations(vector<int> &nums)
    {
        int cnt = 0;
        bool flg = false;
        for (auto &i : nums)
        {
            if ((i == 0 && !flg) or (i == 1 && flg))
            {
                cnt++;
                flg = !flg;
            }
        }
        return cnt;
    }
    int minOperations2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
        }
    }
    int solve(string s){

        int cnt = 0,i = 0,n = s.size();
        while (i < n)
        {
            if(i < n-1 && s[i] == '0' && s[i+1] == '0'){
                //multiply by 100 
                cnt++;
                i += 2;
            }else{
                cnt++;
                i++;
            }
        }
        return cnt;
    }
    int help(vector<int>&a,int n,vector<int>&b,int m,vector<int>&c,int p){
        int cnt = 0;
        for (auto &&i : a)
        {
            for (auto &&j : b)
            {
                for (auto &&k : c)
                {
                    int tmp = (i^j^k);
                    if (__builtin_popcount(tmp) % 2 == 0) {
                    cnt++;
                }
                }
                
            }
            
        }
        return cnt;
    }
};

int main(){
    // long long int 
    string s;cin>>s;
    Solution so;
    vector<int> a = {1, 2};
    vector<int> b = {3};
    vector<int> c = {2,3};
    int n = a.size();
    int m = b.size();
    int p = c.size();
    
    int result = so.help(a, n, b, m, c, p);
    cout  << result << endl;
    cout<<so.solve(s)<<endl;
}
