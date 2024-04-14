// https://leetcode.com/problems/airplane-seat-assignment-probability/description/
#include<bits/stdc++.h>
//sakshi codes here
//its a pure P & C problem where it doesn't matter if n-1 seats vr kon basley jr mi nth seat la pick kele ahe tr
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        //1st person get 1st seat then nth get nth seat p = 1/n
        // 1st person get nth seat then nth cant get his seat p = 1/n
        // 1st person get seat except 1st seat & nth seat then this case has subproblems with size = n-1 
        if(n == 1)
            return 1.0000;
        return (1.00/n + ((n-2.00)/n)*nthPersonGetsNthSeat(n-1));
    }
    //  double nthPersonGetsNthSeat(int n) {
    //     if(n == 1)
    //         return 1.0000;
    //     else
    //         return 1.00/2.00;
    // }
};