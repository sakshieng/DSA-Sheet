/*
1st -> 1. V has stolen a sacred mantra "M". The mantra is an n length string of lowercase letters. Raktbij wishes to corrupt the mantra into a forbidden curse-string "C". Using ancient sorcery, Raktbij can swap letters at a distance d or d+1 in the mantra as many times as he desires. In other words, Raktbij can exchange letters in positions p and q in the mantra M if abs(p-q) = d or abs(p-q) = d + 1

i/p: n = 5 d = 1
    m = "abcde" c = "bcdea"
o/p: yes
swap 0 & 1 in mantra bacde
swap 1 & 2 bcade
swap 2 & 3 bcdae
swap 3 & 4 bcdea

i/p: n = 3 d = 2
m = "abc" c = "abc"
o/p: yes
*/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
class DSU{
public:
    int n;
    vector<int>parent,size;
    DSU(int _n){
        n = _n;
        parent.resize(n,0);
        size.resize(n,0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1; 
        }
        
    }
};
string solve1(int n,int d,string &mantra,string &curse)
{
    //we can group indices that can interact through a series of swaps

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}