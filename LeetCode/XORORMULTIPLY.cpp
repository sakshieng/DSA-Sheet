// https://www.codechef.com/START45D/problems/XORMUL
// for i in range(int(input())):
//     nn,aa,bb = map(int,input().split())
//     x,p = 0,-1
//     for i in range(nn-1,-1,-1):
//         if ((1 << i)&aa) > 0 and ((1 << i)&bb) > 0:
//             continue
//         elif ((1 << i)&aa) == 0 and ((1 << i)&bb) == 0:
//             x |= (1<<i)
//         else:
//             if p == -1:
//                 if ((1 << i)&aa) == 0 and ((1 << i)&bb) > 0: p = 0
//                 else: 
//                     p = 0
//                     x |= (1<<i)
//             else:
//                 if ((1 << i)&aa) == 0 and ((1 << i)&bb) > 0: x|= (1<<i)
//     print(x)
#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{

{
int x = 5;

if(x++ == 5)
cout<<"Five"<<endl;
else
if(++x == 6)
cout<<"Six"<<endl;
return 0;
}
  
}