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
void f1toN(int i,int n){
    //tail recusrion
    if(i > n) return;
    f1toN(i+1,n);
    cout<<i<<" ";
}
void Nto1(int i,int n){
    //head recusrion
    if(i > n) return;
    cout<<i<<" ";
    Nto1(i+1,n);
}
int main()
{
   int i=1,n=10;
   f1toN(i,n);
   cout<<"\n";
   Nto1(i,n);
//    print(5);
   return 0;
}
//head recursion->recursion adhi then logic but when we dont writ base condn this rec fails
//tail recursion->logic adhi then recur
