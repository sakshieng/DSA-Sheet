#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// array of vectors
/*3
3
1 2 3
2 
1 2
4
1 0 2 3
*/
void printVec(vector<int>&v)
{
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int N;
    cin>>N;
    vector<int> v[N];
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;++j)
        // we have to input jth value to ith vecor
        {
            // v is vectors of array and v[i] is single vector
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(int i=0;i<N;++i)
    {
        printVec(v[i]);
    }
}