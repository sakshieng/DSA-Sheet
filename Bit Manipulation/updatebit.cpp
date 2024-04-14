#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// Time complexity of func bitwiseComplement O(ceil(log(n)))
//  while loop for the number of bit of n.
//  n = 2^x ==> (x = number of bits).
//  Ex. n = 10, binary -> 1 0 1 0 (4 bits)
//  10 = 2^x
//  log2(10) = x
//  ceil (log2(10)) = x
//  log2(10) == 3.322, but we represent 10 in 4 bits so take ceil value.
//  Space complexity: O(1)
int bitwiseComplement(int n)
{
    int mask = 1;
    while ((mask & n) != n)
    {
        mask = mask << 1;
        mask += 1;
    }
    return mask ^ n;
}
/*
n=10
binary=1010
do xor of n with mask 1111 we will get ans as 0101
for making this mask we can take 1 and do left shift+1 to make mask=1111
when we do & of n with 1111 we get n itself
now return mask^n
*/
int clearbit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int getbit(int n, int pos)
// position of which we need a bit
{
    return (n & (1 << pos) != 0);
}
int updatebit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    // we cleared the position of bit
    return (n | (value << pos));
    // we take value instead of 1 when value 0 setbit returns 0
}
int main()
{
    cout << getbit(5, 1);
    return 0;
}