//create text file with student records

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream sout("stu.txt");
    int no,mrk;
    char nm[15];
    while(1)
    {
        cout<<"\nRoll no: ";
        cin>>no;
        if(no==0)
            break;
        cout<<"\nName: ";cin>>nm;
        cout<<"\nMarks: ";cin>>mrk;
        sout<<no<<" "<<nm<<" "<<mrk<<endl;
    }
    sout.close();
    return 0;
}