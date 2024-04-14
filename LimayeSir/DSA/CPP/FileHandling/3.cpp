#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
//program to copy file
//source:pqr  destination:abc

using namespace std;

int main()
{
    char ch;
    ifstream in("pqr.txt");
    if(!in)
    {
        cout<<"File not found";
        return 0;
    }
    ofstream out("abc.txt");
    while(1)
    {
        in>>ch; //reads from file
        if(in.eof())
            break;
             
    }
    out<<ch;    //writes to file
    in.close();
    out.close();
    return 0;    
}