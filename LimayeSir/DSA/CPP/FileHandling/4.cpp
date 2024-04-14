#include<fstream>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//writing numbers in a file


int main()
{
    ofstream nout("num.txt");
    int no;
    cout<<"Enter numbers:(0 to stop) ";
    while(1)
    {
        cin>>no;
        if(no==0)
            break;
        nout<<no<<endl;
    }
    nout.close();
    return 0;
}