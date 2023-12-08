#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class STRING
{
    char *str;
    int length;

public:
    STRING()
    {
        length = 0;
        str = new char[length + 1];
    }
    STRING(char *s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    void concat(STRING &A, STRING &B)
    {
        length = A.length + B.length;
        str = new char[length + 1];
        strcat((strcpy(str, A.str)), B.str);
    }
    STRING(STRING &x)
    {
        length = x.length + strlen(x.str);
        str = new char[length + 1];
        strcpy(str, x.str);
    }
    void display()
    {
        cout << str << endl;
    }
};
int main()
{
    STRING A("hu"), B("hua");
    STRING C;
    C.concat(A, B);
    C.display();
    C = B;
    C.display();
    return 0;
}