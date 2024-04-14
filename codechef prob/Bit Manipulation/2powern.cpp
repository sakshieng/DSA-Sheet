#include<iostream>
using namespace std;
// we have to check inputed no is power of 2 or not so we are taking 
// no and its consecutive preceding no and if its 0 then no is 
// in 2 raise to n power
int main(){
    int n;
    cin>>n;
    if((n&n-1)==0){
     cout<<"Yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}