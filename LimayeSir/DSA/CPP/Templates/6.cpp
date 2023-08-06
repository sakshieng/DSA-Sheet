// template func defn outside the class
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
template<class T>//T placeholder object create krtana jo data type yeil toh replace hoil
class tclass
{
    T var[5];//array
public:
    void setData();
    void display();    
};
template<class T>
void tclass<T>::setData(){
    for(int i=0;i<5;++i)
    {
        cout<<"\nData ";
        cin>>var[i];
    }
}
template<class T>
void tclass<T>::display()
{
    cout<<"\nData: ";
    for(int i=0;i<5;++i)
    {
        cout<<var[i]<<" ";
    }
}
int main()
{
   tclass<int>a;//T is replaced by int
   a.setData();
   a.display();
   tclass<double>b;
   b.setData();
   b.display();
   return 0;
}