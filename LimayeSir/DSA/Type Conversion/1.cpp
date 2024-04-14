#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
#define M 10
//program to demonstrate type conversion for user defined type to basic type
class vector
{
    int x[M];
public:
    vector();
    vector(vector &);
    ~vector(){};
    friend istream& operator>>(istream &,vector &);
    friend ostream& operator<<(ostream &,vector &);
    int calcTot();
    operator int()
    {
        return calcTot();
    }
    operator double()
    {
        int tot=*this;
        return double(tot)/M;
        // int che conversion double la honar
    }
    // the way basic type behaves user-defined type behave kryla hva
    // attempting to convert vector to integer
};
int main()
{
//    type casting compiler brobr aslelya basic entity brobr ani type conversion mdhe user defined che convert hote
   return 0;
}
// return double(tot)/M;//c++ type conversion ithe int che conversion double la hotey
// type casting are done for that are avilable for compiler these are for classes 
