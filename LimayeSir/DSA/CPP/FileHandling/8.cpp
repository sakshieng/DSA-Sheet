#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// addition deletion and modification of acc class object by binary file
class accnt
{
    int accNo;
    char accNm[15];
    int accBal;
    int state;
    // state 1(valid record) and state(0) markeed for deletion
public:
    accnt()    
    {
        accNo=accBal=0;
        state=1;
        accNm[0]='\0';//null name adhi assign kra
    }
    ~accnt(){}
    int getNo()
    {
        return accNo;
    }
    char *getNm()
    {
        return accNm;
    }
// in 0 value means no such file exists
    int getBal()
    {
        return accBal;
    }
    int getState()
    {
        return state;
    }
    void delRecord()
    {
        state=0;
    }
    void display();
    void setData(int n);
}accn;
// accn class cha object 21 bytes
// file opened in read mode or in binary mode
void accnt::display()
{
    cout<<"\n"<<setw(4)<<accNo<<" "<<setw(15)<<setiosflags(ios::left)<<accNm<<resetiosflags(ios::left)<<" "<<setw(6)<<accBal<<" "<<state<<"\n";
}
void accnt::setData(int n)
{
    accNo=n;
    cout<<"\nName: ";
    cin>>accNm;
    do
    {
        cout<<"\nOpening balance: ";
        cin>>accBal;
        if(accBal > 500)
            break;
    } while (1);
    state=1;   
}
class accntAMD
{
    fstream fa;
    accnt obj;
public:
    accntAMD();
    ~accntAMD()
    {
        fa.close();
    }
    int search(int);
    // retrun -1 if not found otherwise returns pos in bytes of the record that found
    // object is with fixed no of bytes
    void add();
    void modify();
    void del();
    void display();
};
accntAMD::accntAMD()
{
    // open file with in object
    ifstream in;
    in.open("accnt.dat",ios::in | ios::binary );
     // file reading and writing purpose sathi avilable ahe
    if(!in)//file not found
    {
        ofstream out;
        out.open("accnt.dat",ios::out | ios::binary);
    }
    else
    {
        in.close();
        // necessary for reading and writing
    }
    fa.open("accnt.dat",ios::in | ios::out | ios::binary);
    // open for both reading and writing
}
// in reading out mhnje writing bin mhnje binary mode mdhe file open krne
int main()
{
   
   return 0;
}