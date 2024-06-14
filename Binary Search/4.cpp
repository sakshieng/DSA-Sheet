#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// WE CAN FIND SQUARE ROOT USING BINARY SEARCH
// for root of 2 upto 2-decimal precision search place is 1.00 1.01 1.02 1.03 ------- 1.99 2.00 
// take mid 1+2/2=1.5 check 1.5*1.5 is >< 2 then search place is 1 to 1.5
// for 5-decimal places epsilan
double eps= 1e-6; 
int main()
{
   double x;
   cin>>x;
   double lo=1,hi=x,mid;
//    if we do hi-lo>1 then range misses :: hi-lo>eps
// if we need acuuracy of x decimal places keep eps=10^-x+1
    while(hi-lo>eps)
    {
        // check mid how varies from possible square root
        mid=lo+(hi-lo)/2;
        if(mid*mid<x)
        //for root mid into mid 2 times
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
    }
    cout<< lo <<endl;//or could be hi as well
    cout<<setprecision(10)<<lo<<" "<<hi<<endl;
    // means upto 5 decimal same value and 10 decimal print hotil
    // for verification of root of 2 
    cout<<pow(x,1.0/2)<<endl;
   return 0;
}
