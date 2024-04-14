#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class myTime
{
    int h, m, s;

public:
    myTime()
    {
        h = m = s = 0;
    }
    myTime(int a, int b, int c = 0)
    {
        h = a;
        m = b;
        s = c;
    }
    myTime(long int z)
    {
        h = z / 3600;
        z = z % 3600;
        m = z / 60;
        z = z % 60;
        s = z;
    }
    myTime(myTime &a)
    {
        h = a.h;
        m = a.m;
        s = a.m;
    }
    ~myTime(){};
    void setData()
    {
        cout << "\nH";
        cin >> h;
        cout << "\nM";
        cin >> m;
        cout << "\nS";
        cin >> s;
    }
    void setData(int a, int b = 0, int c = 0)
    {
        h = a;
        m = b;
        s = c;
    }
    void setData(long int z)
    {
        // *this = myTime(z);
        // or
        h = z / 3600;
        z = z % 3600;
        m = z / 60;
        s = z % 60;
    }
    void setData(myTime &t)
    {
        // *this = t;
        // or
        h = t.h;
        m = t.m;
        s = t.s;
    }
    void display()
    {
        cout << "\nH " << h << "\t M " << m << "\t S " << s;
    }
    long int toSec()
    {
        return h * 3600l + m * 60 + s;
    } // string che conversion total seconds mdhe convert
    int gethr()
    {
        return h;
    }
    int getmn()
    {
        return m;
    }
    int getss()
    {
        return s;
    }
    // 2 time asnare func che comparison so convert saglyana to seconds
    int isMore(myTime &k)
    {
        long int a=toSec();
        long int b=k.toSec();
        return (a>b);
    }
    int isLess(myTime &k)
    {
        // return !isMore(k);
        long int a=toSec();
        long int b=k.toSec();
        return a<b;
    }
    myTime add(myTime &b)
    {
        long int p=toSec();
        long int q=b.toSec();
        long int r=p+q;
        myTime k(r);
        return k;
    }
    myTime sub(myTime &b)
    {
        long int p=toSec();
        long int q=b.toSec();
        long int r=labs(p-q);
        myTime k(r);
        return k;
    }
};
