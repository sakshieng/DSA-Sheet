#include <iostream>
#include <string>
using namespace std;

string caesar_cipher(string text, int shift,bool flag) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            if(flag){
                c = (c - 'a' - shift + 26) % 26 + 'a';
            }
            else{
                c = (c - 'a' + shift) % 26 + 'a';
            }
        }
        result += c;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        int shift;
        cin >> shift;
        cin.ignore();
        string message;
        getline(cin, message);

        if (message.find(" the ") != string::npos) {
            cout << caesar_cipher(message, shift,true) << endl;
        } else {
            cout << caesar_cipher(message, shift,false) << endl;
        }
    }

    return 0;
}

