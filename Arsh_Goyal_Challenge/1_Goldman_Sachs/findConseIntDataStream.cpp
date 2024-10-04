// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/
#include<bits/stdc++.h>
//we can use map 
using namespace std;

class DataStream {
public:
int k,freq,value;
    DataStream(int value, int k) {
        /*no need to maintain any ds we have to check last k digits equal ahet ka
        4->false
        insert 4 last 3 number 4 nhit so ->false
        4->true
        3->false last 3 num are 4 4 3
        */
        this->value = value;
        this->k = k;
        freq = 0;
    }
    
    bool consec(int num) {
        if(num == value)
            freq++;
        else
            freq = 0;
        if(freq >= k)
            return 1;
        else
            return 0;
    }
};

