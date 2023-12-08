#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;

        int average = (x + y + z) / 3;

        if (average >= 30) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }

    return 0;
}
