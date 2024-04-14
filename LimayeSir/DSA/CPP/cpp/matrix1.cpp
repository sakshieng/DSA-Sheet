#include <iostream>
#include <iomanip>
using namespace std;
class matrix
{
    // matrix class cha object return krnar returning type matrix
    int x[3][3];
    public :
        matrix();
        matrix(matrix &t);
        ~matrix(){}
        friend istream & operator >> (istream &,matrix &);
        friend ostream & operator << (ostream &,matrix &);
        matrix operator + (matrix &);
        matrix operator - (matrix &);
        matrix operator * (matrix &);
        void operator -();
};

matrix :: matrix()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            x[i][j]=0;
        }
    }
}

matrix :: matrix(matrix &t)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            x[i][j]=t.x[i][j];
        }
    }
}

istream & operator >> (istream &kin,matrix &t)
{
    cout<<"\nMatrix data :";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            kin>>t.x[i][j];
        }
    }
    return kin;
}

ostream & operator << (ostream &kout,matrix &t)
{
    kout<<"\nMatrix data :\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            kout<<" "<<t.x[i][j];
        }
        kout<<endl;
    }
    return kout;
}

matrix matrix :: operator + (matrix &t)
{
    int i,j;
    matrix p;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p.x[i][j]=x[i][j]+t.x[i][j];
        }
    }
    return p;
}

matrix matrix :: operator - (matrix &t)
{
    int i,j;
    matrix p;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p.x[i][j]=x[i][j]-t.x[i][j];
        }
    }
    return p;
}

matrix matrix :: operator * (matrix &t)
{
    int i,j,k;
    matrix p;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                p.x[i][j] += (x[i][k] * t.x[k][j]);
            }
        }
    }
    return p;
}

void matrix :: operator -()
{
    int tmp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<i;j++)
        {
            tmp=x[i][j];
            x[i][j]=x[j][i];
            x[j][i]=tmp;
        }
    }
}

main()
{
    matrix a,b,c;
    cout<<"\nMatrix 1";
    cin>>a;
    cout<<"\nMatrix 2";
    cin>>b;
    c=a+b;
    cout<<a<<b<<c;
    -c;
    cout<<c;
}