#include<bits/stdc++.h>
#include<fstream>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
//create a text file
using namespace std;
/*
ofstream->writing to file
ifstream->reading from file
fstream->reading/writing from file
*/
//getline() method thr string input krta yete 

int main()
{
    ofstream out("pqr.txt");
    //out is object of class ofstream
    char ch;
    while(1)
    {
        cout<<"ENter char(# to break): ";
        cin>>ch;
        if(ch=='#')
            break;
        out<<ch;
        //writes ch 
    }
    out.close();
    return 0;
}