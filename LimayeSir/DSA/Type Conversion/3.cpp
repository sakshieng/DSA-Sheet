#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// type conversion from class to class
class Result//destination
{
    int no;
    double ptr;
public:
    Result()
    {
        no=0;
        ptr=0.0;
    }
    Result(int a,double b)
    {
        no=a;
        ptr=b;
    }
    Result(Result &t)//copy constructor
    {
        no=t.no;
        ptr=t.ptr;
    }
    ~Result(){}
    void display()
    {
        cout<<"\nRoll no"<<no;
        cout<<"\nMarks"<<ptr;
    }
};
class marks//source
{
    int rno;
    int phy,che,mat;
public:
    marks()
    {
        rno=phy=che=mat=0;
    }    
    ~marks(){}
    void setData()
    {
        cout<<"\nRoll no:";
        cin>>rno;
        cout<<"\nMarks:";
        cin>>phy>>che>>mat;
    }
    void display()
    {
        cout<<"\nRoll no"<<rno<<"\nmarks:"<<"\t"<<phy<<"\t"<<che<<"\t"<<mat;
    }
    operator int()
    {
        return rno;
    }
    operator double()
    {
        return (phy+che+mat)/3.0;
    }
    operator Result()
    {
        int a=*this;//marks che conversion int la honar mhnje operator int call hoil ani marks che conversion int la hoil 
        double b=*this;//ithe double mdhle avg marks return hotil
        Result(a,b);
    }
};
// adhichya program mdhe destination class mdhe 
int main()
{
   marks m;
   m.setData();
   m.display();
   Result r;
   r=m; 
   r.display();
   return 0;
}