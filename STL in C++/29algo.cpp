#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// AII_OF,NONE_OF,ANY_OF this have 3rdfunc lambada
bool is_positive(int x)
{
    return x>0;
}
int main()
{
    /*
    auto sum=[](int x,int y){return x+y;};
    cout<<sum(3,5);
    */
    // lambda function 
   cout<< [](int x,int y){return x+y;}(25,7);
cout<<endl;
    vector<int> v={2,4,5};
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;})<<" ";
    cout<<all_of(v.begin(),v.end(),is_positive)<<" ";
   return 0;
}
// for any_of any one +ve when x>0 then return 1
// for none_of none is +ve when x>0 then return 1 (all are negative)
// change return condition acc to requirement x%2==0,x%2!=0 any