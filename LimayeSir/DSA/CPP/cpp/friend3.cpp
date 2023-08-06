#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class Number
{
    int no;
public:
    Number()
    {
        no=0;
    }
    Number(int a)
    {
        no=a;
    }
    Number(Number &t)
    {
        no=t.no;
    }
    ~Number(){}
    friend istream& operator >>(istream &in,Number &t)
    {
        cout<<"\nEnter no:";
        cin>>t.no;
        return in;
    }
    friend ostream& operator <<(ostream &out,Number &t)
    {
        cout<<"\nEnter no:";
        cin>>t.no;
        return out;
    }
    Number operator +(Number &t)
    {
        Number k(no+t.no);
        return k;
    }
    Number operator -(Number &t)
    {
        Number k(labs(no+t.no));
        return k;
    }
    friend Number operator +(int n,Number &t) 
    {
        Number k(n+t.no);
        return k;
        // c=4+b
    }
    friend Number operator -(int n,Number &t) 
    {
        Number k(n-t.no);
        return k;
        // c=4-b
    }
    Number operator ++()//pre incre
    {
        no++;
        return *this;
    }
    Number operator --()//pre decre
    {
        no--;
        return *this;
    }
    Number operator ++(int)//place holder
    {
        Number k(no++);
        return k;
    }
    Number operator --(int)//place holder
    {
        Number k(no--);
        return k;
    }
    void operator -()
    {
        no-=no;
    }
    Number operator +=(int n)
    {
        no+=n;
        return *this;
    }
    Number operator -=(int n)
    {
        no-=n;
        return *this;
    }
    int operator == (int n)
    {
        return no==n;
    }
    int operator ==(Number &k)
    {
        return no=k.no;
    }
};
int main()
{
   Number p(7),q;
   q=++p;
   cout<<p<<q;
   q=p++; 
   cout<<p<<q;
   -p;
   cout<<p;
   if(p==-6) 
    cout<<"\nMatch forund";
   if(p==q) 
        cout<<"\nmatch found";
   else
        cout<<"\nnot found";         
   return 0;
}