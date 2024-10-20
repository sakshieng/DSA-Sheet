#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class H2O {
public:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(m);
        while (turn == 2)
        {
            cv.wait(lock);
        }
        releaseHydrogen();
        ++turn;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex>lock(m);
        while (turn < 2)
        {
            cv.wait(lock);
        }
        releaseOxygen();
        turn = 0;
        cv.notify_all();  
    }
};