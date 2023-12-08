#include <bits/stdc++.h>
using namespace std;
/*******************************************************************************/
class INTEGER{
    float num;
    public:
    INTEGER(){}
    INTEGER(int n){
        num=n;
    }
    INTEGER operator+(INTEGER s){
        INTEGER temp;
        temp.num=num+s.num;
        return temp;
    }
    INTEGER operator-(INTEGER s){
        INTEGER temp;
        temp.num=num-s.num;
        return temp;
    }
    INTEGER operator*(INTEGER s){
        INTEGER temp;
        temp.num=num*s.num;
        return temp;
    }
    INTEGER operator/(INTEGER s){
        INTEGER temp;
        temp.num=(float(num))/s.num;
        return temp;
    }
    void display(){
        cout<<" "<<num<<endl;
    }
};
int main(){
    float a;
    cout<<"Enter the first number for operations :";
    cin>>a;
    INTEGER I1(a);
    float b;
    cout<<"Enter the second number for operations :";
    cin>>b;
    INTEGER I2(b);
    INTEGER sum=I1+I2;
    INTEGER sub=I1-I2;
    INTEGER mult=I1*I2;
    INTEGER div=I1/I2;
    cout<<"Sum operation :"<<a<<"+"<<b<<"=";
    sum.display();
    cout<<"Substraction operation :"<<a<<"-"<<b<<"=";
    sub.display();
    cout<<"Multiplication operation :"<<a<<"*"<<b<<"=";
    mult.display();
    cout<<"Division operation :"<<a<<"/"<<b<<"=";
    div.display();
return 0;
}