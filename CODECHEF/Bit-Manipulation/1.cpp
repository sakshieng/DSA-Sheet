#include<bits/stdc++.h>

using namespace std;
bool isAllBitSet(int n){
   if (((n + 1) & n) == 0)
      return true;
   return false;
}
bool alternate(unsigned int n) {
   unsigned int num = n ^ (n >> 1);
   return isAllBitSet(num);
}
int main()
{
   int t;
   cin>>t;
   while (t--)
   {
        int n;
        cin>>n;
        if(alternate(n))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
   }
   return 0;
}
