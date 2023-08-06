#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int getbit(int n,int pos)
// position of which we need a bit
{
    return (n &(1<<pos)!=0);
}
int main()
{
    cout<<getbit(5,2);
   
   return 0;
}