// CPP program to illustrate substr()
// substr() is a predefined function used for string handling
// This function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object
#include <string.h>
#include <iostream>
using namespace std;
 
int main()
{
    string s1;
    cin>>s1;
    string r = s1.substr(3, 2);
    cout << "String is: " << r;
    return 0;
}