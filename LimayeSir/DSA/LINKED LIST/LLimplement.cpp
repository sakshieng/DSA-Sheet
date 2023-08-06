#include<bits/stdc++.h>
#include "Queueimplement.h"
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

class Slist
{
    NODE *st;
    int cnt;
public:
    Slist()
    {
        st=NULL;
        cnt=0;
    }
    ~Slist();
    void addEnd(int d);
    void addBeg(int d);
    void display();
    int getCount(){ return cnt;}
    void delFirst();
    void delLast();
    void delinode(int pos);
    void delAll();
};

void Slist::addEnd(int d)
{
    NODE* a=new NODE();
    if(st==NULL)
    {
        st=a;
        cnt=1;
    }
    else
    {
        st->setNext(a);
        st=a;
        cnt++;
    }
}
void Slist::addBeg(int d)
{
    NODE *a=new NODE();
    if(st==NULL)
    {
        st=a;
        cnt=1;
    }
    else
    {
        st->setNext(a);
        st=a;
        cnt++;
    }
}

int main()
{
   
   return 0;
}