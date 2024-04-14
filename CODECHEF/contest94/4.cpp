#include <iostream>
#include <string>

using namespace std;


int main() {
    string s;
    int k;

    cout << "Enter the string s: ";
    cin >> s;

    cout << "Enter the monomer length k: ";
    cin >> k;
    int maxi;

    for (int i = 0; i <= s.size() - k; i++) {
        int hydrogenCount = 0;

        for (int j = i; j < i + k; j++) {
            if (s[j] == 'H') {
                hydrogenCount++;
            }
        }

        maxi = max(maxi, hydrogenCount);
    }

    return 0;
}
