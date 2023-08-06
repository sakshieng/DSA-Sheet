#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long unsigned int decimal(string binary) {
    int decimal = 0;
    int n = binary.length();

    for (int i = n - 1; i >= 0; i--) {
        int digit = binary[i] - '0';  

        int power = n - 1 - i;
        int value = digit * pow(2, power);

        decimal += value;
    }

    return decimal;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long unsigned int deci = decimal(s);
        if(deci%12 == 0) cout<<"AC"<<endl;
        else cout<<"WA"<<endl;
    }
    return 0;
}