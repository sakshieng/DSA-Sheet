#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
         vector<int> a(n);
        for (int i = 0; i < n; ++i) cin>>a[i];
        int max_num = *max_element(a.begin(), a.end());
        int result = max_num;
        
        for (int i = 1; i < k; ++i) {
            max_num *= 2;
            result |= max_num;
        }
        
        cout << result << endl;
    }
    return 0;
}
