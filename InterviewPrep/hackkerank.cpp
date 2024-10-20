//typing distance we have given querty keyboard and we need to find path to reach to last char of string
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


int getDistance(string s) {
    vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
    //not a blank space
    //chack kuthe prynt janar
    vector<string>keyboard;
    keyboard.push_back("qwertyuiop");
    keyboard.push_back("asdfghjkl ");
    keyboard.push_back(" zxcvbnm  ");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < keyboard[i].size(); j++) {
            if (keyboard[i][j] != ' ') {
                for (int n = 0; n < 3; n++) {
                    for (int m = 0; m < keyboard[n].size(); m++) {
                        if (keyboard[n][m] != ' ') {
                            dist[keyboard[i][j] - 'a'][keyboard[n][m] - 'a'] = abs(i - n) + abs(j - m);
                            dist[keyboard[n][m] - 'a'][keyboard[i][j] - 'a'] = abs(i - n) + abs(j - m);
                        }
                    }
                }
            }
        }
    }

    s = 'Q' + s;

    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        ans += dist[s[i - 1] - 'A'][s[i] - 'A'];
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string word;
    getline(cin, word);

    int result = getDistance(word);

    fout << result << "\n";

    fout.close();

    return 0;
}
