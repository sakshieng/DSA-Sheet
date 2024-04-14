#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
//tower of hanoi
//a=from rod b=to rod c=auxiliary rod
int towerofHanoi(int n,char a,char b,char c)
{
    if(n==0) return 0;
    towerofHanoi(n-1,a,c,b);
    cout<<"Move disk "<<n<<" from rod "<<a<<" to rod "<<b<<endl;
    towerofHanoi(n-1,c,b,a);
}
int main()
{
   int n=3;
   towerofHanoi(n,'a','c','b');
   return 0;
}