#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// implementation of class Matrix
class Matrix
{
    int a[3][3];
    void init();
public:
    void setData();
    void display();
    void transpose();
    Matrix add(Matrix &);
    Matrix sub(Matrix &);
    Matrix mul(Matrix &);
};
int main()
{
   Matrix a,b,c;
   a.setData(); 
   b.setData(); 
   c=a.add(b);
   a.display();
   b.display();
   c.display();
   c.transpose();
   c.display(); 
   return 0;
}
void Matrix::init()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j]=0;
        }
        
    }
}
void Matrix::setData()
{
    cout<<"\nMatrix data:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
        }
    }
}
void Matrix::display()
{
    cout<<"\nMatrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<setw(4)<<a[i][j];
                cout<<endl;
        }
    }
}
Matrix Matrix::add(Matrix &q)
{
    Matrix r;
    r.init();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            r.a[i][j]=a[i][j]+q.a[i][j];
        }
    }
    return r;
}
Matrix Matrix::sub(Matrix &q)
{
    Matrix r;
    r.init();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            r.a[i][j]=a[i][j]-q.a[i][j];
        }
    }
    return r;
}
Matrix Matrix::mul(Matrix &q)
{
    int k;
    Matrix r;
    r.init();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            r.a[i][j]+=a[i][k]*q.a[k][j];
        }
    }
    return r;
}