#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template<class T>
class tclass
{
    T var;
public:
    void setData(){
        cout<<"\nData: ";
        cin>>var;
    }    
    void display()
    {
        cout<<"\nData: "<<var;
    }
};
int main()
{
   tclass<int>a;
   a.setData();
   a.display();
   tclass<double>b;
   b.setData();
   b.display();
   return 0;
}