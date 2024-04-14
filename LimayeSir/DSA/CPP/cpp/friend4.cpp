#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

class stu
{
    int rno;
    char nm[15];
public:
    stu()
    {
        rno=0;
        nm[0]='\0';
    }
    stu(stu &k)
    {
        rno=k.rno;
        strcpy(nm,k.nm);
    }
    ~stu(){}
    int getNo()
    {
        return rno;
    }
    char *getName()
    {
        return nm;
    }
    friend istream& operator >>(istream &in,stu &b)
    {
        cout<<"\nRoll no=";
        in>>b.rno;
        cout<<"\nName=";
        in>>b.nm;
        return in;
    }
    friend ostream& operator <<(ostream &out,stu &b)
    {
        out<<"\nRoll no="<<b.rno;
        out<<"\nName="<<b.nm;
        return out;    
    }
};
int main()
{
   stu a;
   cin>>a;
   cout<<a; 
   return 0;
}