#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// by using comparator fuc^n we can define custom sorting algorithm from inbult algorithm
// sort(from which sorting has to be started,next element upto which sorting is done)
/* this inbulit algo is combi of
        1.quick sort
        2.heap sort
        3.insertion sort
fastest method of sorting
*/
bool should_i_swap(int a,int b)
{
    if(a<b)
    return true;
    else
    return false;
}
int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i=0;i<n ; ++i)
   {
        cin>>a[i];
   }
   for(int i=0;i<n;++i)
   {
        for(int j=i+1;j<n;++j)
        {
            if(should_i_swap(a[i],a[j]))
            {
                swap(a[i],a[j]);
            }
        }
   }
   for(int i=0;i<n;++i)
   {
        cout<< a[i] <<" ";
   }
   return 0;
}
