#include<bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
   string line;
   char ch;
   cout<<"Enter data to be inserted:\n";
   cin>>line;
   ofstream obj("hello.txt",ios::app);
   obj<<"The data to be inserted\n";
   obj<<line<<endl;
   obj.close();
   fstream sakshi("hello.txt",ios::in);
   cout<<"File contents are:";
   while(sakshi.eof() == 0)
   {
        sakshi.get(ch);
        cout<<ch;
   }
   sakshi.close();
   return 0;
}
