//program to read text file
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    ifstream in("pqr.txt");
    // in is the object of class ifstream
    if(!in)
    {
        cout<<"File not found";
        return 0;
    }
    while(1)
    {
        in>>ch;
        if(in.eof())
        // string chi last bit check krte
            break;
        cout<<ch;
    }
    in.close();
    return 0;
}