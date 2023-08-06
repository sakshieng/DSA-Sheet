#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// type conversion from class to class
class marks
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
};
class Result
{
    int no;
    double ptr;
public:
    Result()
    {
        no=0;
        ptr=0.0;
    }
    // hya class mdhe marks class che variables use kele tr nhi chalat
    // marks convert honar double la at ptr by calling operator double and same marks convert to int by calling operator int
    Result(marks &t)
    {
        //marks cha t ha object ahe
        no=t;
        ptr=t;
    }
    Result(Result &t)
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

int main()
{
   marks m;
   m.setData();
   m.display();
   Result r(m);
   r.display(); 
   return 0;
}