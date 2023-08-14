#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// infinite recursion without base condition
//Every recursive call needs extra space in the stack memory
//recursion implementation is done by stack so infinite recursion call will lead to segmentation fault
int cnt=0;
void print(int n)
{
    if(n==1) return;
    // cout<< n <<endl;    //when u write cout before func call teh func la call jatana print honar
    //TC of code is no of func calls * complexity of each func    
    print(n-1);
    cout<< n <<endl;        
}
int main()
{
   print(5);
   return 0;
}