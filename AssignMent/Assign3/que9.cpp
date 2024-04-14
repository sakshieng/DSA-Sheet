#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
class String{
    public:
    string str;
    int operator==(String s2){
        if(str==s2.str)
            return 1;
        else
            return 0; 
        }
};
void check(String s1,String s2){
        if(s1==s2){
            cout<<"Strings are equal."<<endl;
        }
        else{
            cout<<"Strings are not equal."<<endl;
        }
    }
int main(){
    String S1,S2;
    cout<<"Enter the first string :";
    cin>>S1.str;
    cout<<"Enter the second string :";
    cin>>S2.str;
    check(S1,S2);
return 0;
}