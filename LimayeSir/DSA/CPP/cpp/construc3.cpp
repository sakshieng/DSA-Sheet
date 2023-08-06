// we are allocating the memory explcitly by dynobj.a this could be deleted by destructor so we have to write code in destructor
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class dynobj
{
    // array chya compare mdhe better approach 
    int noe;
    int *ptr;
public:
    dynobj();
    dynobj(int);    
    dynobj(dynobj &);    
    ~dynobj()
    {
        delete[]ptr;
    }
    void setData();
    void display();
    int total();
    int avg()
    {
        return total()/noe;
    }
};
// default constructor
dynobj::dynobj()
{
    noe=5;
    ptr=new int[noe];
}
dynobj::dynobj(int a)
{
    noe=a;
    ptr=new int[noe];
}
dynobj::dynobj(dynobj &t)
{
    noe=t.noe;
    ptr=new int[noe];
    for (int i = 0; i < noe; i++)
    {
        ptr[i]=t.ptr[i];
    }
}
void dynobj::setData()
{
    cout<<"\nEnter data:";
    for (int i = 0; i < 10; i++)
    {
        cin>>ptr[i];
    }
}
void dynobj::display()
{
    cout<<"\nData\n";
    for (int i = 0; i < noe; i++)
    {
        cout<<" "<<ptr[i];
    }
}
int dynobj::total()
{
    int i=1,tot=ptr[0];
    while (i<noe)
    {
        tot += ptr[i+1];
    }
    return tot;
}
int main()
{
//  no of elements 7 tya nusar memory block reserve honar  
   dynobj a(7);
   a.setData();
   a.display();
   cout<<"\nTotal:"<<a.total()<<"\nAvg:"<<a.avg(); 
   return 0;
}