// A class constructor is a special member function of a class that is executed whenever we create new objects of that class.
/*
class A
{
    public:
    int i;
    A();//constructor declared
}
//constructor defn
A::A()
{
    i=1;
}
*/
#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

class MyClass
{                    // The class
public:              // Access specifier
    int myNum;       // Attribute (int variable)
    string myString; // Attribute (string variable)
};

int main()
{
    MyClass myObj; // Create an object of MyClass

    // Access attributes and set values
    myObj.myNum = 15;
    myObj.myString = "Some text";

    // Print attribute values
    cout << myObj.myNum << "\n";
    cout << myObj.myString;
    return 0;
}
