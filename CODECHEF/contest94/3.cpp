

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sakshi cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c){
    return (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u');
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k=0;
        cin >> n ;
        string s,p;
        cin >> s >>p;
        for(int i=0;i<n;++i){
             if(p[i] == '1') k++;
        }
        if((k ==0 || k==n) and (s != p)) no;
        else yes;
    }
    return 0;
}