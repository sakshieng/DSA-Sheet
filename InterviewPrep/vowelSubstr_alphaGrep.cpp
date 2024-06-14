// https://maang.in/mocks/attempts/2170?problem_id=521
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
int solve(string word) {
    int n = word.length();
    
    int arr[26] = {0}; 
    int i = 0, j = 0, count = 0, ans = 0;
    
    while (j < n) {
        char ch = word[j];
        
        if (isVowel(ch)) {
            if (arr[ch - 'a'] == 0) {
                count++;
            }
            arr[ch - 'a']++;

            if (count == 5) {
                int val = i;
                int temp[26];
                memcpy(temp, arr, sizeof(temp));
                
                while (count == 5) {
                    ans++;
                    
                    char c = word[val];
                    temp[c - 'a']--;
                    if (temp[c - 'a'] == 0) {
                        count--;
                    }
                    val++;
                }
                count = 5;
            }
        } else {
            i = j + 1;
            count = 0;
            memset(arr, 0, sizeof(arr));
        }

        j++;
    }
    
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s;getline(cin,s);
        cout<<solve(s)<<"\n";
    }
    return 0;
}