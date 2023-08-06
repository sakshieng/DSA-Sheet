/*
Sample Input 
2
7
abacaaa
8
abacaaef

3
3
An index is called to be beautiful if it has even number of charcter 'a' on left side as well as on right side
*/
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;



int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        int total=0;
        
       vector<int>v(n);
 for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            v[i] = 1;
            total++;
        }
    }
        
        for (int i = 0; i < n; i++) {
        v[i] += v[i-1];
    }
        int cnt=0;

    for (int i = 0; i < n; i++) {
        int left = v[i];
        int right = total - left;
        
        if (s[i] == 'a') {
            left--;
        } 

        if (left % 2 == 0 && right % 2 == 0) {
            cnt++;
        }
    }
        cout<<cnt<<endl;
    }

    return 0;
}
