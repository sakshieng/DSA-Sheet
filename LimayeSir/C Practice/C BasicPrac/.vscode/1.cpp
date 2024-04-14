#include <iostream>
using namespace std;
int main() {
    int x;
    cin>>x;
for (int k = 31; k >= 0; k--) {
if (x &(1<<k)) 
cout << "1";
else cout << "0";
}

}