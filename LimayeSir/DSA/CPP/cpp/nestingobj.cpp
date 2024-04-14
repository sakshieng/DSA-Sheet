#include <bits/stdc++.h>
#include "array.h"
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
class Result
{
    int rno;
    Array mrk;
public:
    Result() { rno = 0; }
    ~Result() {}
    void setData()
    {
        cout << "\nRoll no:";
        cin >> rno;
        mrk.setData();
    }
    void display()
    {
        cout << "\nResult\nRoll no:" << rno;
        mrk.display();
        cout << "\nTotal:" << mrk.total();
        cout << "\nAvg:" << mrk.avg();
    }
    int getNo()
    {
        return rno;
    }
    int getTotal()
    {
        return mrk.total();
    }
    int getAvg()
    {
        return mrk.avg();
    }
};
int main()
{
    Result vp;
    vp.setData();
    vp.display();
    return 0;
}