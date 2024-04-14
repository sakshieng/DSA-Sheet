#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
/*
        A
        |
        B----C
        |
        D
*/
class D:public B,public C
{
protected:
    int mrk;
public:
    D():B(),C()    
    {
        mrk=0;
    }
    ~D(){}
    void set()
    {
        B::set();
        cout<<"\nTheroy marks "
    }
}
int main()
{
    
   dobj.set();
   dobj.display();
   return 0;
}