// https://leetcode.com/problems/destroying-asteroids/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int>pq;
        long long ans = mass;
        for(auto &i:asteroids)
            pq.push(i);
        for (int i = 0; i < pq.size(); i++)
        {
            if(ans >= pq.top())
                continue;
            if(ans < pq.top())
                return 0;
            ans += pq.top();
            pq.pop();
        }
        return 1;
    }
};
/*
asteroid = {5, 2, 1, 8} mass = 10
pq->{8, 5, 2, 1}->max heap
1st ans = 10 ans>top(8) continue
2nd ans = 18 ans>top(5) continue
3rd ans = 23 ans>top(2) continue
4th ans = 25 ans>top(1) continue
loop complete->true
*/