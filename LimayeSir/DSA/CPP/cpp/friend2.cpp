#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class myTime
{
    int h, m, s;
    long int tosec()
    {
        return h * 3600 + m * 60 + s;
    }

public:
    myTime()
    {
        h = m = s = 0;
    }
    myTime(int a, int b = 0, int c = 0)
    {
        h = a;
        m = b;
        s = c;
    }
    myTime(myTime &k)
    {
        h = k.h;
        m = k.m;
        s = k.s;
    }
    myTime(long int sec)
    {
        h = sec / 3600;
        int z = sec % 3600;
        m = z / 60;
        s = z % 60;
    }
    ~myTime() {}
    friend istream &operator>>(istream &in, myTime &k)
    {
        cout << "\nEnter time in hr ";
        in >> k.h;
        cout << "\nEnter time in min ";
        in >> k.m;
        cout << "\nEnter time in sec ";
        in >> k.s;
        return in;
    }
    friend ostream &operator<<(ostream &out, myTime &k)
    {
        out << "\nhr" << k.h;
        out << "\tmin" << k.m;
        out << "\tsec" << k.s;
        return out;
    }
    int operator<(myTime &k)
    {
        return tosec() < k.tosec();
    }
    int operator>(myTime &k)
    {
        return tosec() > k.tosec();
    }
    int operator==(myTime &k)
    {
        return tosec() == k.tosec();
    }
    myTime operator+(myTime &k)
    {
        myTime t(tosec() + k.tosec());
        return t;
    }
    myTime operator-(myTime &k)
    {
        myTime t(labs(tosec() - k.tosec()));
        return t;
    }
};
// p q r r=p+q
//  if(p>q) cout<<p else cout<<q
int main()
{
    myTime r;
    myTime p(12, 10, 90);
    myTime q(20, 20, 90);
    r = p + q;
    if (p > q)
        cout << p;
    else
        cout << q;
    return 0;
}
// 2 object same class che friend
// 1 object 1 class tevha member class  