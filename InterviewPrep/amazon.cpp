/*
1.amazon is offering discount on every purchase on pair of products whose cost sum is divisible by x
i/p: n = 5 x = 60 cost = [31,25,85,29,35]
o/p: 3 pairs are [31,29],[25,35],[85,35]
*/

#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
void first()
{
    int n;cin>>n;
    vector<int>cost(n);
    int x;cin>>x;
    for (auto &&i : cost)
    {
        cin >> i;
    }
    long long ans = 0;
    map<int,long long>mp;
    for (int i = 0; i < n; i++)
    {
        int val = cost[i]%x;
        int target = x - val;
        ans += mp[target];

        if(val == 0)
            val = x;
        mp[val]++;
    }
    // for(auto &i:mp) {
    //     cout << i.first << " "<<i.second<<endl;
    // }
    cout << ans << endl;
    
}
/*
2. amazon have launched new game each has 3 rounds 
a player x is capable of defeating plyaer y if there exists some arrrangement
power boosters of x = [9,5,11] & y = [7,12,3]
-> if y uses in order [3,7,12] x can use it in order [11,9,5] as 11>3 & 9>7
-> if x uses in order [5,9,11] y can use it in order [7,12,3] as 7>5 & 12>9

find no of players who are capable of defeating all other players in game 
input has set of power boosters a,b,c

i/p: n = 4
    a = [3,4,1,16]
    b = [2,11,5,6]
    c = [8,7,9,10]
o/p: 2
for player 1 : 4 vs 2,11 vs 8,7 vs 3 wins all 3
for player 3: 4 vs 1,11 vs 9,7 vs 5 wins all 3
for player 4: 4 vs 16,11 vs 10,7 vs 6 wins last 2
*/

void second(){
    int n;cin>>n;
    vector<int>a(n); for(int &i:a) cin>>i;
    vector<int>b(n); for(int &i:b) cin>>i;
    vector<int>c(n); for(int &i:c) cin>>i;
    vector<vector<int>>vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i].push_back(a[i]);
        vp[i].push_back(b[i]);
        vp[i].push_back(c[i]);
        sort(vp[i].begin(),vp[i].end());
    }
    sort(vp.begin(),vp.end());
    multiset<int>st[3]; //3 multisets to keep track of maximum values from each column of vp array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            st[i].insert(vp[j][i]);
        }
    }
    //print vp
    //it will have sorted order of all 3 elements of each player
    // for(auto &i:vp){
    //     for(auto &j:i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    auto canWin = [&](int i){
        int first = vp[i][0];// Largest in column 0
        int second = vp[i][1];
        int third = vp[i][2];
        st[0].erase(st[0].find(first));
        st[1].erase(st[1].find(second));
        st[2].erase(st[2].find(third));
        int remainingFirst = *st[0].rbegin();
        int remainingSecond = *st[1].rbegin();
        int remainingThird = *st[2].rbegin();
        st[0].insert(first);
        st[1].insert(second);
        st[2].insert(third);
        //we need 2nd compare to be greater than 1st and 3rd compare to be greater than 2nd
        return third > remainingSecond && second > remainingFirst; 
    };
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(canWin(i))
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // first();
    second();
    return 0;
}