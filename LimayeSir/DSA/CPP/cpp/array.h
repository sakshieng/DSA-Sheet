#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
#define M 10
// constructor fun defination outside the class
class Array
{
    int x[M];
public:
    Array();    
    Array(Array &);
    Array(int);
    ~Array(){};
    void setData();
    void display();
    void set(int pos,int d)
    {
        x[pos] = d;
    }
    int get(int pos)
    {
        return x[pos];
    }
    int total();
    int avg()
    {
        return total()/M;
    }
    int isMore(Array &t)
    {
        return total() > t.total();
    }
    int isMore(int val)
    {
        return total() > val;
    }
    int isLess(Array &t)
    {
        return total() < t.total();
    }
    int isLess(int val)
    {
        return total() < val;
    }
};
int Array::total()
{
    int tot=x[0],i=1;
    while (i < M)
    {
        tot += x[i++];
    }
    return tot;
}
Array::Array()
{
    for (int i = 0; i < M; i++)
    {
        x[i] = 0;
    }
}
// constructor func with non-return type
Array::Array(int z)
{
    for(int i=0;i<M;i++)
    {
        x[i] = z;
    }
}
Array::Array(Array &t)
{
    for (int i = 0; i < M; i++)
    {
        x[i] = t.x[i];
    }
}
void Array::setData()
{
    cout<<"\nData:\n";
    for (int i = 0; i < M; i++)
    {
        cin>>x[i];
    }
}
void Array::display()
{
    cout<<"\nData:\n";
    for (int i = 0; i < M; i++)
    {
        cout<<" "<<x[i];
    }
}
