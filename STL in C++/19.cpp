#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/
int main()
{
//    we use ordered sets here as last element is max element here erase that last element and add add half of that to set again dont use sets here as duplicates get stored wrong ans yeil mg
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    multiset<long long>bags;
   long long int candy_count;
    for(int i=0;i<n;++i)
    {
    cin>>candy_count;
    // insert that eatable candy count to bag again
    bags.insert(candy_count);
  }
//   remove k times candy as we have that much of time to eat them
// as bags.end() is next to last iterator hence do -1
long long int total_cnt=0;
for(int i=0;i<k;++i)
{
    // remove last iterator
    auto last_it=(--bags.end());
    // auto last_it=bags.end();
    // last_it--;
// we can do above 2 steps as well
   candy_count = (*last_it);
    // value at last_it is assigned to count
    total_cnt+=(candy_count);
    // count is added to total
    bags.erase(last_it);
    // erase that max no of candies
    bags.insert(candy_count/2);
    // add max/2 candies to bag again
}
cout<<total_cnt<<endl;
    } 
   return 0;
}