/*
stl is divided into 4 parts
1.Containers
2.Iterators
3.Algorithms
4.Functors

Containers are of 3 types:
1.Sequential-->vectors,stack,queue
2.Ordered-->maps,multimap,set,multiset
3.Unordered-->unordered map,unordered set

Iterators are used to point memory address of containers
example is-->begin(),end()

Algorithms are defined for e.g.upper bound,lower bound,sort(comparator-->custom sorting data allow),max,min,accumalate(can find sum),reverse,count,find,next permutations,previous permutations

Functors are classes which can act as function(Not imp in CP)

*/
#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   pair<int,string>p;
//    we can make pairs of any data types,containers
p=make_pair(2,"abc");
// declare can be by pair={2,"abc"};
pair<int,string> p1=p;
p1.first=3;
// but when we do pair<int,string> &p1=p;then output will be 3,abc
cout<<p.first<<" "<<p.second<<endl;
   return 0;
}

