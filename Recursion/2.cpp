#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// proper base condition
int cnt=0;
void print()
{
    if(cnt == 3)
        return;
    cout<<cnt<<endl;    
    cnt++;
    print();    
}
int main()
{
   print();
   return 0;
}
// recursion--> function that calls itself is known as a recursive function. And, this technique is known as recursion.
