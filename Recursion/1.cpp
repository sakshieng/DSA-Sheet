#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// infinite recursion without base condition
//Every recursive call needs extra space in the stack memory
int cnt=0;
void print()
{
    cout<< 1 <<endl;        
    print();
}
int main()
{
   print();
   return 0;
}