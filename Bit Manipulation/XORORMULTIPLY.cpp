// https://www.codechef.com/START45D/problems/XORMUL
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int nn, aa, bb;
        cin >> nn >> aa >> bb;
        int x = 0, p = -1;
        
        for (int i = nn - 1; i >= 0; i--) {
            if (((1 << i) & aa) > 0 && ((1 << i) & bb) > 0) {
                continue;
            } else if (((1 << i) & aa) == 0 && ((1 << i) & bb) == 0) {
                x |= (1 << i);
            } else {
                if (p == -1) {
                    if (((1 << i) & aa) == 0 && ((1 << i) & bb) > 0) p = 0;
                    else {
                        p = 0;
                        x |= (1 << i);
                    }
                } else {
                    if (((1 << i) & aa) == 0 && ((1 << i) & bb) > 0) x |= (1 << i);
                }
            }
        }
        
        cout << x << endl;
    }
    
    return 0;
}
