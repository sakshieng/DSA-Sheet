#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/convert-decimal-to-irreducible-fraction_630530?leftPanelTab=0
vector<long long> convertToIrreducible(string integerPart, string fractionalPart) 
{
    // fractional part 8 size so multiply by 10^8

    long long num = stoll(integerPart)*100000000 + stoll(fractionalPart);
    long long deno = pow(10,fractionalPart.size());;
    
    long long gcd = __gcd(num, deno);
    while(gcd > 1) {
        num /= gcd;
        deno /= gcd;
        gcd = __gcd(num, deno);
    }
    return {num, deno};
}
