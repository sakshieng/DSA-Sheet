#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// AGGRESSIVE COWS
const int N=1e5+10;
int n,cows;
// n-->no of stalls
int positions[N];
// search space size 1e9
bool canPlaceCows(int minDist)
{
    // we havent placed cow anywhere :: -1
    int lastPos=-1;
    // as int cows is global variable :: make a copy of that in this func
    int cows_ct=cows;
    // search where we put last cow and could we place cow at current place 
    for(int i=0;i<n;++i)
    {
        if(positions[i]-lastPos>=minDist || lastPos==-1)
        {
            // lastPos==-1 is true only for first cow
            cows_ct--;
            lastPos=positions[i];
        }
        if(cows_ct==0) break;
    }
    // all cows are placed 
    if(cows_ct==0) return true;
    else return false;
}
int main()
{
//    we have to maximize the minimum distance betn cows which is occured at last true make predicate fun of distance between cows it will only return T or F
   int t;
   cin>>t;
   while (t--)
   {
    cin>>n>>cows;
    for(int i=0;i<n;++i)
    {
        cin>>positions[i];
    }
    sort(positions,positions+n);
    // TTTTTTTTTTTFFFFFFF
    int lo=0,hi=1e9;//max stalls
    while(hi-lo>1)
    {
        int mid=(hi-lo)/2+lo;
        if(canPlaceCows(mid))
        {
            // if this return true ::keep it in search place
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(canPlaceCows(hi))
    cout<<hi<<endl;
    else
    cout<<lo<<endl;
   }
    
   return 0;
}