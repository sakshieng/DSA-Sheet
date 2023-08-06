#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// UPPER BOUND-->first position of next higher number than last occurrence of num 

// LOWER BOUND-->position of just higher number than num
int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;++i)
   {
      cin>>a[i];
   }
   sort(a.begin(),a.end());
   for(int i=0;i<n;++i)
   {
      cout<<a[i]<<endl;
   }
   cout<<endl;
   // input:4 25 6 5 5 9 8 2
   auto it = upper_bound(a.begin(),a.end(),5);
   // auto it = lower_bound(a.begin(),a.end(),5);  
   if(it == a.end())

   {
      cout<<"Not Found";
      return 0;
   }
   cout<<(*it)<<endl;
   return 0;
}

//for maps and sets use auto it = s.lower_bound(5); and auto it = s.upper_bound(3); <-- has TC O(log(n)) if we write like arrays and vectors for maps and sets then have TC O(n)
