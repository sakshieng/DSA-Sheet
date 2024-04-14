#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/
/*
//FFFFFTTTTTTT First T find krto apan
the array which is formed by min possible max int is monotonic arr
d1 d2 divisors 
x/d1=12/3->3 6 9 12
x/d2->2 4 6 8 10 12
12/lcm(3,2)=12/6=2

x/d1->(x-x/d1)->arr1
x/d2->(x-x/d2)->arr2
(x-x/lcm(d1,d2))->elmts which will appear in both arrays
to find max value we will use binary search
*/
#define ll long long
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll lcm = (divisor1*(ll)divisor2/(__gcd(divisor1,divisor2)));
        //new style of writing func
        auto solve = [&] (int x){
            ll a = x-x/divisor1;
            ll b = x-x/divisor2;
            ll c = x-x/lcm;
            //ek c kmi kryche karan a>cnt1>cnt2 satisfy vhyla & a+b kela ki common part don vela count jhala
            c = max((ll)0,a+b-c);
            if(a>=uniqueCnt1 and b>=uniqueCnt2 and a+b-c>=uniqueCnt1+uniqueCnt2)
                return 1;
            return 0;
        };

        //binary search
        int low = 0,high = INT_MAX;
        while (low < high)
        {
            int mid = low + (high-low)/2;
            if(solve(mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;//first minimum integer by which 2 arrays are formed
    }
};