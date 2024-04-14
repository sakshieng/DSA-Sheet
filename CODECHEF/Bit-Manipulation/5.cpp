#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
       int t;cin>>t;
        while(t--){
        int n;cin>>n;
            int a[n];
            for (int i = 0; i < n; ++i) cin>>a[i];
            int maxi = 0;
        for (int i = 30; i >= 0; --i) {
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] & (1 << i))
                ++count;
        }

        if (count >= 2 || (count == 1 && maxi & (1 << i)))
            maxi |= (1 << i);
    }
            cout<<maxi<<endl;
    }
    return 0;
}