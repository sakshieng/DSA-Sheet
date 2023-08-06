#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// multilevel inheritance
class MyClass {
  public:
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};

class MyChild: public MyClass {
};

class MyGrandChild: public MyChild {
};

int main() {
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}
int main()
{
   
   return 0;
}
    