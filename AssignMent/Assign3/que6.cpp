#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
class Polar{
    float r,a,x,y;
    public:
    Polar(){}
    Polar(float radius,float ang){
        r=radius;
        a=ang;
        x=r*cos(ang);
        y=r*sin(ang);
    }
    Polar operator+(Polar s){
        Polar temp;
        temp.x=x+s.x;
        temp.y=y+s.y;
        return temp;
    }
    void recToPolar(){
        float rad=sqrt(x*x+y*y);
        float ang=atan(y/x);
        float ang1=(float(ang*180))/3.14;
        cout<<"Radius and angle after addition of two polar form are "<<rad<<" "<<ang1<<endl;
    }
};
int main(){
    float r1,a1,r2,a2;
    cout<<"Enter the radius and angle of first :";
    cin>>r1>>a1;
    float ang1=(float(3.14*a1)/180);
    cout<<"Enter the radius and angle of second :";
    cin>>r2>>a2;
    float ang2=(float(3.14*a2)/180);
    Polar c1(r1,ang1);
    Polar c2(r2,ang2);
    Polar c3=c1+c2;
    c3.recToPolar();
return 0;
}
