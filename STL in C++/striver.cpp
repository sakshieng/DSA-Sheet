#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

namespace sakshi
{
    int val = 100;
    int getVal()
    {
        return val * 10;
    }
}
int main()
{
    int val = 10;
    cout << val << endl;              // gives 10
    cout << sakshi::getVal() << endl; // gives 1000
    return 0;
}
// array<int,5> arr={1,2,3,4,5};
// for(auto it:arr.begin();it!=arr.end();++it){
// cout<<(*it)<<" ";
//  }

// for each loop
// for(auto it : arr){
//     cout<<(it)<<" ";
// }

// for reverse iteration
// for(auto it:arr.rbegin();it>arr.rend();++it){
//  cout<<(*it)<<" ";
//   }

// empalce_back()<==>push_back but TC(emplace_back())<TC(push_back())



    // define vector 10*20
    // vector<vector<int> vec(10,vector<int>(20,0));