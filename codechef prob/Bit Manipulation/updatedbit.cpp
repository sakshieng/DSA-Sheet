#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
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
    cout << updatebit(5, 1, 1);
    return 0;
}