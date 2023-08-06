
#include<bits/stdc++.h>
using namespace std;

int main()
{
        ifstream file;
        char s, fname[100];

        cout<<"Enter file name to read :: ";
        cin>>fname;

        ifile.open(fname);

        if(!ifile)
        {
                cout<<"\nError in opening file..!!\n";

                exit(0);
        }

        cout<<"\n";

        while(ifile.eof()==0)
    {
        ifile>>s;
        cout<<s<<" ";
    }
    
        cout<<"\n";
        ifile.close();

return 0;

}

