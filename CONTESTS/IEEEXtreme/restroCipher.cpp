#include<bits/stdc++.h>

using namespace std;

char extractLetters(string input) {
    map<char, int> charFrequency;
    for (char c : input) {
        if (c >= 'a' && c <= 'g') {
            charFrequency[c]++;
        }
    }
    char maxChar = 'a';  
    int maxFreq = 0;     

    for (const auto& pair : charFrequency) {
        if (pair.second > maxFreq) {
            maxChar = pair.first;
            maxFreq = pair.second;
        }
    }
    return maxChar;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string message;
        getline(cin, message);
        char letter = extractLetters(message);
        letter = toupper(letter);
        cout << letter << endl;
    }

    return 0;
}
